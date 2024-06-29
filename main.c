/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:30:29 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/01 15:04:15 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_and_ceiling(t_game *g)
{
	int	y;
	int	x;

	y = -1;
	while (++y <= HEIGHT)
	{
		x = -1;
		if (y <= HEIGHT / 2)
			while (++x <= WIDTH)
				ft_my_mlx_pixel_put(g, WIDTH - x, y, g->t.c_rgb);
		else
			while (++x <= WIDTH)
				ft_my_mlx_pixel_put(g, WIDTH - x, y, g->t.f_rgb);
	}
}

int	render_game(t_game *g)
{
	floor_and_ceiling(g);
	raycasting(g);
	mlx_put_image_to_window(g->mlx, g->win,
		g->mini.img, 10, 10);
	return (0);
}

int	end_game(t_game *g)
{
	free_info(g);
	exit(0);
}

void	_init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->w, g->h, "Cub3D");
	g->img = mlx_new_image(g->mlx, g->w, g->h);
	g->addr = mlx_get_data_addr(g->img, &g->bits_per_pixel,
			&g->line_length, &g->endian);
	get_data_texture(g);
	init_minimap(g);
	mlx_loop_hook(g->mlx, &render_game, g);
	mlx_hook(g->win, 2, 1L << 0, key_pressed, g);
	mlx_hook(g->win, 6, 1L << 6, mouse_rotation, g);
	mlx_hook(g->win, 17, 0, end_game, g);
	mlx_loop(g->mlx);
}

int	main(int ac, char **av)
{
	t_game	g;

	if (ac != 2 || !file_ext(av[1]))
		return (ft_error(ERR_ARG));
	init_params(&g);
	get_info(&g, av[1]);
	if (!g.pg->ch_pg || check_zeros(&g) || check_player(&g)
		|| !check_char(&g) || g.pg_count > 1)
	{
		free_info(&g);
		return (ft_error("Error: Something wrong with the map\n"));
	}
	_init_mlx(&g);
	free_info(&g);
	return (0);
}
