/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:30:49 by vpescete          #+#    #+#             */
/*   Updated: 2023/08/01 15:08:40 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "include/libft/libft.h"
# include "minilibx/mlx.h"
# include "src/gnl/get_next_line.h"

# define ERR_ARG "You have to choose a .cub file\n"
# define ERR_FILE "Something wrong with the file .cub\n"
# define WIDTH 800
# define HEIGHT 500
# define NORD 0
# define SOUTH 1
# define EAST 2
# define WEST 3

typedef struct s_mmap
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
}	t_mmap;

typedef struct s_pg
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		map_x;
	int		map_y;
	char	ch_pg;
}	t_pg;

typedef struct s_map
{
	int		r;
	int		c;
	char	**mat;
}	t_map;

typedef struct s_ray
{
	double	cam_x;
	double	dir_x;
	double	dir_y;
	double	s_dist_x;
	double	s_dist_y;
	double	d_dist_x;
	double	d_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	pwall_d;
}	t_ray;

typedef struct t_draw
{
	int	line_h;
	int	d_start;
	int	d_end;
}	t_draw;

typedef struct s_data
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
}	t_data;

typedef struct s_tex
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		f_rgb;
	int		c_rgb;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
	double	wall_x;
	t_data	n;
	t_data	s;
	t_data	w;
	t_data	e;
}	t_tex;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
	double	time;
	double	old_time;
	t_pg	*pg;
	t_map	map;
	t_ray	*ray;
	t_draw	*draw;
	t_tex	t;
	t_mmap	mini;
	int		map_w;
	int		map_h;
	double	speed;
	double	rotate_speed;
	int		pg_count;
}	t_game;

typedef enum e_keys
{
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	C = 8,
	K_UP = 126,
	K_DOWN = 125,
	K_LEFT = 123,
	K_RIGHT = 124,
	ENTER_1 = 36,
	ENTER_2 = 76,
}	t_keys;

/* ERROR FUNCTIONS */
int		file_ext(char *file);
int		ft_error(char *s);
int		check_char(t_game *g);
int		end_game(t_game *g);
int		err(t_game *g);
/* PARSER FUNCTIONS */
void	get_info(t_game *g, char *s);
void	save_texture(t_game *g, char *line);
void	save_color(t_game *g, char *line);
int		check_ismap(char *s);
void	count_line(t_game *g, int fd, char *line);
void	save_map(t_game *g, int fd, char *line);
void	get_info_utils(t_game *g, int *fd, char *line, char *line_2);
int		check_zeros(t_game *g);
int		check_player(t_game *g);

/* HOOK FUNCTIONS */
int		key_pressed(int key, t_game *g);
int		mouse_rotation(int x, int y, t_game *g);
void	rotate(t_game *g, double r_speed);

/* PG FUNCTIONS */
void	set_pg_position(t_game *g);
void	get_pg_direction(t_game *g, int i, int j);
void	set_pg_nord(t_game *g);
void	set_pg_south(t_game *g);
void	set_pg_east(t_game *g);
void	set_pg_west(t_game *g);

/* MAP FUNCTIONS */
void	init_minimap(t_game *g);
void	update_minimap(t_game *g, int old_x, int old_y);
void	draw_case(t_game *g, int x, int y, int color);

/* UITILS FUNCTIONS */
void	free_info(t_game *game);
void	print_info(t_game *g);
void	free_matrix(t_game *g);

/* DRAW FUNCTIONS */
int		create_trgb(int t, int r, int g, int b);
void	draw_line(t_game *g, int x, int start, int end);
void	draw_element(t_game *g, int x);
int		ft_my_mlx_pixel_put(t_game *g, int x, int y, int color);
void	get_fc(t_game *g);
void	get_data_texture(t_game *g);
void	define_tex(t_game *g);
int		get_color(t_game *g, int x, int y, int i);

/* DDA FUNCTIONS */
void	perform_dda(t_game *g);

/* RAYCASTING FUNCTIONS */
void	raycasting(t_game *g);
void	calc_step_side_d(t_game *g);
void	calc_wall_dist(t_game *g);
void	init_params(t_game *g);
void	init_ray(t_game *g);

#endif
