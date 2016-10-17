/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:18:10 by fde-monc          #+#    #+#             */
/*   Updated: 2016/10/17 15:18:11 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include "math.h"
# include <stdio.h>
# define ERROR(ID) (ft_strcmp(ID, id) == 0 ? 1 : 0)
# define WHITE 0x00FFFFFF
# define Y_MAX all->y_max
# define X_MAX all->x_max
# define BUFF_SIZE 50

typedef struct	s_dot
{
	int				x;
	int				y;
	int				z;
	struct s_dot	*next;
}				t_dot;

typedef struct	s_fdf
{
	int		**tab;
	t_dot	**dots;
	int		x_max;
	int		y_max;
	int		x_og;
	int		y_og;
	int		height;
	int		zoom;
	void	*mlx;
	void	*win;
}				t_fdf;

typedef struct	s_line
{
	int	x;
	int	y;
	int	xd;
	int	yd;
	int	color;
}				t_l;

int				usage(char *id);
int				error(char *id);

int				check_file(char **av, t_fdf *all);
int				read_file1(int fd);
int				check_line1(char *line);
int				read_file2(int fd);
int				check_line2(char *line);

int				**make_tab(int fd, int y_max, int x_max);
int				*make_line(int fd, int x_max);
char			**splitmap(char *line, int x_max);

int				get_infos(char *file, t_fdf *all);
void			get_dots(t_fdf *all);
t_dot			*init_list(t_fdf *all);
t_dot			*make_node(int x, int y, int z);

int				run_mlx(t_fdf *all);
void			print_fdf(t_fdf *all);
void			print_line(t_dot *og, t_dot *gol, t_fdf *all);
int				set_line(t_l *l, t_dot *og, t_dot *gol, t_fdf *all);
int				drawline(t_l *l, t_fdf *all);
int				printline(t_l *l, t_fdf *all);
int				print_std(t_l *l, t_fdf *all);

void			affiche_tab_debug(int **tab, int y_max, int x_max);
void			debug_affmap(char **tab);
void			debug_list(t_fdf *all);

int				get_pixelpos_x(int x, int y);
int				get_pixelpos_y(int x, int y);

int				read_commands(t_fdf *all);
int				keypress(int keycode, void *param);
int				move_og(int keycode, t_fdf *all);

#endif
