/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pg_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:53:20 by vpescete          #+#    #+#             */
/*   Updated: 2023/07/31 20:37:34 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	set_pg_nord(t_game *g)
{
	g->pg->dir_x = 0;
	g->pg->dir_y = -1;
	g->pg->plane_x = 0.66;
	g->pg->plane_y = 0;
}

void	set_pg_south(t_game *g)
{
	g->pg->dir_x = 0;
	g->pg->dir_y = 1;
	g->pg->plane_x = -0.66;
	g->pg->plane_y = 0;
}

void	set_pg_east(t_game *g)
{
	g->pg->dir_x = 1;
	g->pg->dir_y = 0;
	g->pg->plane_x = 0;
	g->pg->plane_y = -0.66;
}

void	set_pg_west(t_game *g)
{
	g->pg->dir_x = -1;
	g->pg->dir_y = 0;
	g->pg->plane_x = 0;
	g->pg->plane_y = 0.66;
}
