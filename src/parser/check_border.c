/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:47:43 by vpescetelli       #+#    #+#             */
/*   Updated: 2023/08/01 11:15:04 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_zeros(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.mat[++i])
	{
		j = -1;
		while (g->map.mat[i][++j])
		{
			if (g->map.mat[i][j] == '0')
			{
				if (!g->map.mat[i][j + 1] || !g->map.mat[i][j - 1] || i == 0 ||
					i == g->map.r - 1)
					return (1);
				else if (g->map.mat[i][j + 1] == 32
				|| g->map.mat[i][j - 1] == 32
				|| g->map.mat[i + 1][j] == 32
				|| g->map.mat[i - 1][j] == 32 || g->map.mat[i][j + 1] == '\n'
				|| g->map.mat[i + 1][j] == '\n' || g->map.mat[i - 1][j] == '\n')
					return (1);
			}
		}
	}
	return (0);
}

int	check_player(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.mat[++i])
	{
		j = -1;
		while (g->map.mat[i][++j])
		{
			if (g->map.mat[i][j] == g->pg->ch_pg)
			{
				if (!g->map.mat[i][j + 1] || !g->map.mat[i][j - 1] || i == 0
					|| i == g->map.r - 1)
					return (1);
				else if (g->map.mat[i][j + 1] == 32
				|| g->map.mat[i][j - 1] == 32
				|| g->map.mat[i + 1][j] == 32 || g->map.mat[i - 1][j] == 32
				|| g->map.mat[i][j + 1] == '\n'
				|| g->map.mat[i + 1][j] == '\n' || g->map.mat[i - 1][j] == '\n')
					return (1);
			}
		}
	}
	return (0);
}
