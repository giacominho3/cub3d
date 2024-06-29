/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:12:16 by vpescetelli       #+#    #+#             */
/*   Updated: 2023/08/04 11:31:34 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	save_texture(t_game *g, char *line)
{
	if (!strncmp(line, "NO", 2))
		g->t.no = ft_strtrim(ft_strdup(line), "NO .\n");
	else if (!strncmp(line, "SO", 2))
		g->t.so = ft_strtrim(ft_strdup(line), "SO .\n");
	else if (!strncmp(line, "WE", 2))
		g->t.we = ft_strtrim(ft_strdup(line), "WE .\n");
	else if (!strncmp(line, "EA", 2))
		g->t.ea = ft_strtrim(ft_strdup(line), "EA .\n");
}

void	save_color(t_game *g, char *line)
{
	if (!strncmp(line, "F", 1))
	{
		g->t.f = ft_strdup(line);
		g->t.f = ft_strtrim(g->t.f, "F./ \n");
	}
	else if (!strncmp(line, "C", 1))
	{
		g->t.c = ft_strdup(line);
		g->t.c = ft_strtrim(g->t.c, "C./ \n");
	}
}

int	check_ismap(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '1')
			return (0);
	}
	return (1);
}
