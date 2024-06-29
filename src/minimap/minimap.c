/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:53:30 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/04 12:15:20 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	update_minimap(t_game *g, int old_x, int old_y)
{
	draw_case(g, (int)g->pg->pos_x * 7, (int)g->pg->pos_y * 7, 0xEEEE20);
	if ((int)g->pg->pos_x != old_x)
		draw_case(g, old_x * 7, old_y * 7, g->t.c_rgb);
	if ((int)g->pg->pos_y != old_y)
		draw_case(g, old_x * 7, old_y * 7, g->t.c_rgb);
}

void	minimap_pix_put(t_game *g, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > HEIGHT - 1 || x < 0
		|| x > WIDTH - 1)
		return ;
	pixel = (g->mini.addr + (y * g->mini.line_length
				+ x * (g->mini.bits_per_pixel / 8)));
	*(int *)pixel = color;
}

void	draw_case(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = 7;
	while (i > 0)
	{
		j = 7;
		while (j > 0)
		{
			minimap_pix_put(g, x + j, y + i, color);
			j--;
		}
		i--;
	}
}

void	draw_minimap(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map.mat[i])
	{
		j = 0;
		while (g->map.mat[i][j])
		{
			if (g->map.mat[i][j] == '1')
				draw_case(g, j * 7, i * 7, 0x000000);
			else if (g->map.mat[i][j] == '0')
				draw_case(g, j * 7, i * 7, g->t.c_rgb);
			else if (g->map.mat[i][j] == g->pg->ch_pg)
				draw_case(g, j * 7, i * 7, 0xEEEE20);
			else
				draw_case(g, j * 7, i * 7, 0x000000);
			j++;
		}
		i++;
	}
}

void	init_minimap(t_game *g)
{
	g->mini.img = mlx_new_image(g->mlx, g->map_w * 7, g->map_h * 7);
	g->mini.addr = mlx_get_data_addr(g->mini.img, &g->mini.bits_per_pixel,
			&g->mini.line_length, &g->mini.endian);
	draw_minimap(g);
}
