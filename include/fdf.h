/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:52:23 by nvoltair          #+#    #+#             */
/*   Updated: 2024/06/17 04:56:07 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*malloc, free*/
# include <stdlib.h>
/*perror, strerror*/
# include <stdio.h>
/*open, close:*/
# include <fcntl.h>
/*maths!*/
# include <math.h>
/*graphical framework libraries*/
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/includes/ft_printf.h"

# define MLX_ERROR 1
# define HEIGHT_DIST 1.1
# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900
# define SPLIT_FAIL_MSG "couldn't split: malloc error?\n"
# define USAGE_MSG "Expected usage : ./fdf [filename].fdf\n"
# define WHITE 0xffffff
# define RED 0xff0000
# define GREEN 0x55218
// # define GREEN 0x00ff00
# define BLUE 0x0000ff
# define LITEBLU 0x0298a6
# define YELLOW 0xfcba00
# define PI 3.14159265

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
}	t_mlx;

typedef struct s_mapdata
{
	int		height;
	int		width;
	int		peak;
	int		valley;
	int		has_color;
	int		**map;
	int		**colors;
}	t_mapdata;

typedef struct s_point
{
	double	x;
	double	y;
	int 	color;
}	t_point;

typedef struct s_line
{
	t_point from;
	t_point	towards;
	t_img *img;
}	t_line;

typedef struct s_egment
{
	int start;
	int	end;
	int st_col;
	int end_col;
}	t_segment;

typedef struct s_angles
{
	double	x;
	double	y;
	double	z;
}	t_angles;

typedef struct s_fdf
{
	t_mlx		mlx;
	t_mapdata	mapdata;
	t_angles	angles;
	int			x_offset;
	int			y_offset;
	int			to_scale;
	double		h_dist;
	double		zoom;
}	t_fdf;

	/*parse & process data*/
int		**map_alloc(int height, int width);
char	***colors_alloc(int height, int width);
int		map_dim(int fd, t_mapdata *mapdata);
int		mapcheck(int ac, char **av, t_mapdata *mapdata);
int		mapchecker(t_fdf *fdf, char *str);
void	color_case(t_mapdata *mapdata, char *line, int k, int i);
int		is_color_coded(char *str);
int		is_hexcode(char c);
int		right_format(char c);
void	free_map(int **map, int height);
void	free_str(char **str);
void	free_colors(char ***str);
void	free_maps(t_mapdata *mapdata);
size_t	wordcount(char const *s, char c);
void	compute_offsets(t_fdf *fdf);
void	setup_default(t_fdf *fdf);
	/*RGB madness*/
void	img_pix_put(t_img *img, int x, int y, int color);
int		z_dependant_color(t_mapdata *mapdata, int z);
int		color_this_pxl(int current, t_segment segment);
	/*Maths and geometry*/
int		within_bounds(int x, int y);
int		min_of_2(int a, int b);
int		round_it(double val);
double	fpart(double val);
double	abs_valu(double x);
void	swap(double *a, double *b);
t_point	space_2_iso_plan(t_fdf fdf, t_mapdata *mapdata, int i, int j);
double	rotate_3d_coord(t_point *ret, t_angles rotas, int x, int y , int z);
int		corner_draw(t_fdf *fdf, int i, int j);
int		edge_draw(t_fdf *fdf, int i, int j);
int		corner_draw_two(t_fdf *fdf, int i, int j);
double	percent(int start, int end, int current);
	/*Rasterizing*/
void	line2seg(t_line line, t_segment *segment);
void	positiv_slope(t_line line, t_segment segment, double i, int j);
void	negativ_slope(t_line line, t_segment segment, double i, int j);
void	draw_it(t_line line, double i, int j, double slope);
int		naive_line(t_img *img, t_point from, t_point towards);
	/*GUI*/
int	pop_the_window(t_fdf *fdf);
int		kill_win(t_fdf *fdf);
void	gui_info(t_fdf fdf);
int		handle_input(int keysym, t_fdf *fdf);
void	handle_input2(int keysym, t_fdf *fdf);

#endif