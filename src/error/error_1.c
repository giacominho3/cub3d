/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:55:39 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/01 15:08:30 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	err(t_game *g)
{
	free_info(g);
	ft_error(ERR_FILE);
	exit(1);
}

int	ft_error(char *s)
{
	printf("%s", s);
	return (1);
}

int	valid_char(char c, char *set)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (c == set[i])
			return (1);
	}
	return (0);
}

int	check_char(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.mat[++i])
	{
		j = -1;
		while (g->map.mat[i][++j])
		{
			if (valid_char(g->map.mat[i][j], " 01NSWE\n"))
			{
				if (valid_char(g->map.mat[i][j], "NSWE"))
					g->pg_count++;
			}
			else
				return (0);
		}
	}
	return (1);
}
