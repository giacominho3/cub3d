/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:23:30 by vpescetelli       #+#    #+#             */
/*   Updated: 2023/08/01 11:12:50 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw(t_game *g, int x, int start, int texture)
{
	int	color;

	color = get_color(g, g->t.tex_x, g->t.tex_y, texture);
	ft_my_mlx_pixel_put(g, x, start, color);
}

void	draw_wall(t_game *g, int x, int start, int end)
{
	while (start < end)
	{
		g->t.tex_pos = (start - HEIGHT / 2
				+ g->draw->line_h / 2) * g->t.step;
		g->t.tex_y = (int)g->t.tex_pos & (64 - 1);
		g->t.tex_pos += g->t.step;
		if (g->ray->side == 1 && g->ray->dir_y > 0)
			draw(g, WIDTH - x, start, SOUTH);
		else if (g->ray->side == 1 && g->ray->dir_y < 0)
			draw(g, WIDTH - x, start, NORD);
		else if (!g->ray->side && g->ray->dir_x < 0)
			draw(g, WIDTH - x, start, WEST);
		else if (!g->ray->side && g->ray->dir_x > 0)
			draw(g, WIDTH - x, start, EAST);
		start++;
	}
}

void	draw_line(t_game *g, int x, int start, int end)
{
	while (start < end)
	{
		ft_my_mlx_pixel_put(g, WIDTH - x, start, 16711680);
		start++;
	}
}

void	draw_element(t_game *g, int x)
{
	g->draw->line_h = (int)(g->h / g->ray->pwall_d);
	g->draw->d_start = -(g->draw->line_h) / 2 + g->h / 2;
	if (g->draw->d_start < 0)
		g->draw->d_start = 0;
	g->draw->d_end = g->draw->line_h / 2 + g->h / 2;
	if (g->draw->d_end >= g->h)
		g->draw->d_end = g->h - 1;
	define_tex(g);
	draw_wall(g, x, g->draw->d_start, g->draw->d_end);
}

int	ft_my_mlx_pixel_put(t_game *g, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT)
		return (-1);
	dst = g->addr + (y * g->line_length + x * (g->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	int newdst = ft_atoi(dst);
	return (newdst);
}
