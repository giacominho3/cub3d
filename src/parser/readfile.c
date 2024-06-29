/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:01:18 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/04 12:11:49 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	count_line(t_game *g, int fd, char *line)
{
	while (line)
	{
		g->map.r++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	save_map(t_game *g, int fd, char *line)
{
	int	i;

	i = -1;
	g->map_w = 1;
	g->map.mat = ft_calloc(g->map.r + 1, sizeof(char *));
	while (line)
	{
		g->map.mat[++i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		if ((int)ft_strlen(g->map.mat[i]) >= g->map_w)
			g->map_w = ft_strlen(g->map.mat[i]);
	}
	g->map.mat[++i] = NULL;
	free(line);
}

void	get_info_utils(t_game *g, int *fd, char *line, char *line_2)
{
	while (line)
	{
		if (!strncmp(line, "NO", 2) || !strncmp(line, "SO", 2)
			|| !strncmp(line, "WE", 2) || !strncmp(line, "EA", 2))
			save_texture(g, line);
		else if (!strncmp(line, "F", 1) || !strncmp(line, "C", 1))
			save_color(g, line);
		else if (!check_ismap(line))
		{
			count_line(g, fd[0], line);
			save_map(g, fd[1], line_2);
			g->map_h = g->map.r;
			return ;
		}
		free(line);
		free(line_2);
		line = get_next_line(fd[0]);
		line_2 = get_next_line(fd[1]);
	}
}

void	get_data_texture(t_game *g)
{
	int	i;
	int	j;

	i = 64;
	j = 64;
	g->t.n.img = mlx_xpm_file_to_image(g->mlx, g->t.no, &i, &j);
	if (!g->t.n.img)
		err(g);
	g->t.n.addr = mlx_get_data_addr(g->t.n.img, &g->t.n.bits_per_pixel,
			&g->t.n.line_length, &g->t.n.endian);
	g->t.s.img = mlx_xpm_file_to_image(g->mlx, g->t.so, &i, &j);
	if (!g->t.s.img)
		err(g);
	g->t.s.addr = mlx_get_data_addr(g->t.s.img, &g->t.s.bits_per_pixel,
			&g->t.s.line_length, &g->t.s.endian);
	g->t.w.img = mlx_xpm_file_to_image(g->mlx, g->t.we, &i, &j);
	if (!g->t.w.img)
		err(g);
	g->t.w.addr = mlx_get_data_addr(g->t.w.img, &g->t.w.bits_per_pixel,
			&g->t.w.line_length, &g->t.w.endian);
	g->t.e.img = mlx_xpm_file_to_image(g->mlx, g->t.ea, &i, &j);
	if (!g->t.e.img)
		err(g);
	g->t.e.addr = mlx_get_data_addr(g->t.e.img, &g->t.e.bits_per_pixel,
			&g->t.e.line_length, &g->t.e.endian);
}

void	get_info(t_game *g, char *s)
{
	int		fd[2];
	char	*line;
	char	*line_2;

	fd[0] = open(s, O_RDONLY);
	fd[1] = open(s, O_RDONLY);
	line = get_next_line(fd[0]);
	line_2 = get_next_line(fd[1]);
	get_info_utils(g, fd, line, line_2);
	set_pg_position(g);
	close(fd[0]);
	close(fd[1]);
	get_fc(g);
}
