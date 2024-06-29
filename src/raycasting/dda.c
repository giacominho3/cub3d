/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescetelli <vpescetelli@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:19:46 by vpescetelli       #+#    #+#             */
/*   Updated: 2023/07/28 11:20:13 by vpescetelli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	perform_dda(t_game *g)
{
	if (g->ray->s_dist_x < g->ray->s_dist_y)
	{
		g->ray->s_dist_x += g->ray->d_dist_x;
		g->pg->map_x += g->ray->step_x;
		g->ray->side = 0;
	}
	else
	{
		g->ray->s_dist_y += g->ray->d_dist_y;
		g->pg->map_y += g->ray->step_y;
		g->ray->side = 1;
	}
	if (g->map.mat[(int)g->pg->map_y][(int)g->pg->map_x] == '1')
		g->ray->hit = 1;
}
