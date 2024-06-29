/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:16:36 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/04 11:26:09 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_tex(t_game *g)
{
	g->t.c_rgb = 0;
	g->t.f_rgb = 0;
	g->t.n.addr = NULL;
	g->t.tex_x = 0;
	g->t.tex_y = 0;
	g->t.tex_pos = 0;
	g->t.step = 0;
}

void	init_params(t_game *g)
{
	g->pg = (t_pg *)ft_calloc(1, sizeof(t_pg));
	g->w = WIDTH;
	g->h = HEIGHT;
	g->old_time = 0;
	g->draw = ft_calloc(1, sizeof(t_draw));
	g->map.c = 0;
	g->map.r = 0;
	g->speed = 0.12;
	g->rotate_speed = -0.07;
	g->pg_count = 0;
	init_ray(g);
	init_tex(g);
}
