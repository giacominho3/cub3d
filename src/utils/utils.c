/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:24:41 by vpescetelli       #+#    #+#             */
/*   Updated: 2023/08/01 11:19:52 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_matrix(t_game *g)
{
	int	i;

	i = -1;
	while (g->map.mat[++i])
		free(g->map.mat[i]);
	free(g->map.mat);
}

void	free_info(t_game *game)
{
	free(game->t.c);
	free(game->t.f);
	free(game->t.no);
	free(game->t.so);
	free(game->t.we);
	free(game->t.ea);
	free_matrix(game);
	free(game->ray);
	free(game->draw);
	free(game->pg);
}

int	file_ext(char *file)
{
	int	i;

	i = open(file, O_RDONLY);
	if (i < 0)
	{
		printf("Error: file not exist\n");
		exit(0);
	}
	i = ft_strlen(file);
	if (file[i - 1] == 'b' && file[i - 2] == 'u'
		&& file[i - 3] == 'c' && file[i - 4] == '.')
		return (1);
	return (0);
}
