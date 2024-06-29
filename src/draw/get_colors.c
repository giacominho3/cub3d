/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:34:28 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/01 15:08:16 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_rgb(char **av)
{
	if (!av[0] || (ft_atoi(av[0]) <= 0 || ft_atoi(av[0]) >= 255))
		return (0);
	else if (!av[1] || ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) >= 255)
		return (0);
	else if (!av[2] || ft_atoi(av[2]) <= 0 || ft_atoi(av[2]) >= 255)
		return (0);
	return (1);
}

void	ft_free_mtx(char **mtx)
{
	int	i;

	i = -1;
	while (mtx[++i])
		free(mtx[i]);
	free(mtx);
}

void	set_f_rgb(t_game *g, char **mtx)
{
	g->t.f_rgb = ft_atoi(mtx[0]);
	g->t.f_rgb = (g->t.f_rgb << 8) + ft_atoi(mtx[1]);
	g->t.f_rgb = (g->t.f_rgb << 8) + ft_atoi(mtx[2]);
}

void	set_c_rgb(t_game *g, char **mtx)
{
	g->t.c_rgb = ft_atoi(mtx[0]);
	g->t.c_rgb = (g->t.c_rgb << 8) + ft_atoi(mtx[1]);
	g->t.c_rgb = (g->t.c_rgb << 8) + ft_atoi(mtx[2]);
}

void	get_fc(t_game *g)
{
	char	**f_mtx;
	char	**c_mtx;

	if (!g->t.c || !g->t.f)
		err(g);
	f_mtx = ft_split(g->t.f, ',');
	c_mtx = ft_split(g->t.c, ',');
	if (!check_rgb(f_mtx) || !check_rgb(c_mtx))
	{
		ft_free_mtx(f_mtx);
		ft_free_mtx(c_mtx);
		err(g);
	}
	set_f_rgb(g, f_mtx);
	set_c_rgb(g, c_mtx);
	ft_free_mtx(f_mtx);
	ft_free_mtx(c_mtx);
}
