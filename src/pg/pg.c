/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:26:25 by gifulvi           #+#    #+#             */
/*   Updated: 2023/08/01 12:12:15 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	get_pg_direction(t_game *g, int i, int j)
{
	if (g->map.mat[i][j] == 'N')
		set_pg_nord(g);
	else if (g->map.mat[i][j] == 'S')
		set_pg_south(g);
	else if (g->map.mat[i][j] == 'E')
		set_pg_east(g);
	else if (g->map.mat[i][j] == 'W')
		set_pg_west(g);
	else
		return ;
	g->pg->ch_pg = g->map.mat[i][j];
}

void	set_pg_position(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.mat[++i])
	{
		j = -1;
		while (g->map.mat[i][++j])
		{
			if (g->map.mat[i][j] == 'N' || g->map.mat[i][j] == 'S' ||
				g->map.mat[i][j] == 'E' || g->map.mat[i][j] == 'W')
			{
				g->pg->pos_x = j;
				g->pg->pos_y = i;
				get_pg_direction(g, i, j);
			}
		}
	}
}
