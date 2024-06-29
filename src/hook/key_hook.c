/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:40:19 by vpescetelli       #+#    #+#             */
/*   Updated: 2023/08/01 11:14:32 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	mouse_rotation(int x, int y, t_game *g)
{
	(void)y;
	if (g->pg->ch_pg == 'N' || g->pg->ch_pg == 'S')
	{
		if (x > (int)(WIDTH / 1.2))
			rotate(g, g->rotate_speed / 3);
		else if (x < WIDTH / 6)
			rotate(g, -g->rotate_speed / 3);
	}
	else
	{
		if (x > (int)(WIDTH / 1.2))
			rotate(g, -g->rotate_speed / 3);
		else if (x < WIDTH / 6)
			rotate(g, g->rotate_speed / 3);
	}
	return (0);
}

void	rotate(t_game *g, double r_speed)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = g->pg->dir_x;
	tmp_plane_x = g->pg->plane_x;
	g->pg->dir_x = g->pg->dir_x * cos(r_speed) - g->pg->dir_y * sin(r_speed);
	g->pg->dir_y = tmp_dir_x * sin(r_speed) + g->pg->dir_y * cos(r_speed);
	g->pg->plane_x = g->pg->plane_x * cos(r_speed) - g->pg->plane_y
		* sin(r_speed);
	g->pg->plane_y = tmp_plane_x * sin(r_speed) + g->pg->plane_y * cos(r_speed);
}

void	move(t_game *g, double next_x, double next_y, char sign)
{
	int	old_x;
	int	old_y;

	old_x = g->pg->pos_x;
	old_y = g->pg->pos_y;
	if (sign == '+')
	{
		if (g->map.mat[(int)g->pg->pos_y][(int)(g->pg->pos_x + next_x)] != '1')
			g->pg->pos_x += next_x;
		if (g->map.mat[(int)(g->pg->pos_y + next_y)][(int)g->pg->pos_x] != '1')
			g->pg->pos_y += next_y;
	}
	else if (sign == '-')
	{
		if (g->map.mat[(int)g->pg->pos_y][(int)(g->pg->pos_x - next_x)] != '1')
			g->pg->pos_x -= next_x;
		if (g->map.mat[(int)(g->pg->pos_y - next_y)][(int)g->pg->pos_x] != '1')
			g->pg->pos_y -= next_y;
	}
	if ((old_x != g->pg->pos_x) || (old_y != g->pg->pos_y))
		update_minimap(g, old_x, old_y);
}

int	key_pressed(int key, t_game *g)
{
	if (key == ESC)
	{
		mlx_destroy_window(g->mlx, g->win);
		exit(0);
	}
	else if (key == C)
		mlx_string_put(g->mlx, g->win, 550, 520, 16393683, "Keys");
	else if (key == W)
		move(g, g->pg->dir_x * g->speed, g->pg->dir_y * g->speed, '+');
	else if (key == A)
		move(g, g->pg->plane_x * g->speed, g->pg->plane_y * g->speed, '+');
	else if (key == S)
		move(g, g->pg->dir_x * g->speed, g->pg->dir_y * g->speed, '-');
	else if (key == D)
		move(g, g->pg->plane_x * g->speed, g->pg->plane_y * g->speed, '-');
	else if ((key == K_LEFT && (g->pg->ch_pg == 'N' || g->pg->ch_pg == 'S'))
		|| (key == K_RIGHT && (g->pg->ch_pg == 'E' || g->pg->ch_pg == 'W')))
		rotate(g, -g->rotate_speed);
	else if ((key == K_RIGHT && (g->pg->ch_pg == 'N' || g->pg->ch_pg == 'S'))
		|| (key == K_LEFT && (g->pg->ch_pg == 'E' || g->pg->ch_pg == 'W')))
		rotate(g, g->rotate_speed);
	return (0);
}
