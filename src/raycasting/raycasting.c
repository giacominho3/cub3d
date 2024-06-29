/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:18:41 by vpescetelli       #+#    #+#             */
/*   Updated: 2023/08/04 11:26:37 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	define_tex(t_game *g)
{
	if (g->ray->side == 0)
		g->t.wall_x = g->pg->pos_y + g->ray->pwall_d * g->ray->dir_y;
	else
		g->t.wall_x = g->pg->pos_x + g->ray->pwall_d * g->ray->dir_x;
	g->t.wall_x -= floor(g->t.wall_x);
	g->t.tex_x = g->t.wall_x * 64;
	if (!g->ray->side && g->ray->dir_x > 0)
		g->t.tex_x = 64 - g->t.tex_x - 1;
	if (g->ray->side == 1 && g->ray->dir_x < 0)
		g->t.tex_x = 64 - g->t.tex_x - 1;
	g->t.step = 1.0 * 64 / g->draw->line_h;
}

void	raycasting(t_game *g)
{
	int	x;

	x = -1;
	while (++x <= g->w)
	{
		g->ray->cam_x = 2 * x / (double)g->w - 1;
		g->ray->dir_x = g->pg->dir_x + g->pg->plane_x * g->ray->cam_x;
		g->ray->dir_y = g->pg->dir_y + g->pg->plane_y * g->ray->cam_x;
		g->pg->map_x = (int)g->pg->pos_x;
		g->pg->map_y = (int)g->pg->pos_y;
		g->ray->hit = 0;
		calc_wall_dist(g);
		calc_step_side_d(g);
		while (g->ray->hit == 0)
			perform_dda(g);
		if (g->ray->side == 0)
			g->ray->pwall_d = g->ray->s_dist_x - g->ray->d_dist_x;
		else
			g->ray->pwall_d = g->ray->s_dist_y - g->ray->d_dist_y;
		draw_element(g, x);
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
}

void	calc_step_side_d(t_game *g)
{
	if (g->ray->dir_x < 0)
	{
		g->ray->step_x = -1;
		g->ray->s_dist_x = (g->pg->pos_x - g->pg->map_x) * g->ray->d_dist_x;
	}
	else
	{
		g->ray->step_x = 1;
		g->ray->s_dist_x = (g->pg->map_x + 1.0
				- g->pg->pos_x) * g->ray->d_dist_x;
	}
	if (g->ray->dir_y < 0)
	{
		g->ray->step_y = -1;
		g->ray->s_dist_y = (g->pg->pos_y - g->pg->map_y) * g->ray->d_dist_y;
	}
	else
	{
		g->ray->step_y = 1;
		g->ray->s_dist_y = (g->pg->map_y + 1.0
				- g->pg->pos_y) * g->ray->d_dist_y;
	}
}

void	calc_wall_dist(t_game *g)
{
	g->ray->d_dist_x = fabs(1 / g->ray->dir_x);
	g->ray->d_dist_y = fabs(1 / g->ray->dir_y);
}

void	init_ray(t_game *g)
{
	g->ray = ft_calloc(1, sizeof(t_ray));
	g->ray->s_dist_x = 0;
	g->ray->s_dist_y = 0;
	g->ray->step_x = 0;
	g->ray->step_y = 0;
	g->ray->dir_x = 0;
	g->ray->dir_y = 0;
	g->ray->d_dist_x = 0;
	g->ray->d_dist_y = 0;
}
