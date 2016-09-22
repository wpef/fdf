#ifndef FDF_H
# define FDF_H
# include "libft.h"
# define ERROR(ID) (ft_strcmp(ID, id) == 0 ? 1 : 0)
# define BUFF_SIZE 50

typedef struct	s_dots
{
	int				id;
	int				x;
	int				y;
	int				z;
	struct s_dots	*next;
}				t_dots;

typedef struct	s_fdf
{
	t_dots	*dots;
	int		x_max;
	int		y_max;
}				t_fdf;

int	usage(char *id);
int	error(char *id);

int	check_file(char **av);
int	read_file1(int fd);
int	check_line1(char *line);
int	read_file2(int fd);
int	check_line2(char *line);

t_fdf	get_infos(char *file, int x_max);
t_dots	*make_list(char *line, int y);
t_dots	*make_node(char *dot, int x, int y);

#endif
