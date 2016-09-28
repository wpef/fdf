#ifndef FDF_H
# define FDF_H
# include "libft.h"
# define ERROR(ID) (ft_strcmp(ID, id) == 0 ? 1 : 0)
# define BUFF_SIZE 50

typedef struct	s_fdf
{
	int		**tab;
	int		x_max;
	int		y_max;
}				t_fdf;

int	usage(char *id);
int	error(char *id);

int	check_file(char **av, t_fdf *all);
int	read_file1(int fd);
int	check_line1(char *line);
int	read_file2(int fd);
int	check_line2(char *line);

int **make_tab(int fd, int y_max, int x_max);
int	*make_line(int fd, int x_max);
char	**splitmap(char *line, int x_max);

int	get_infos(char *file, t_fdf *all);
void	affiche_tab_debug(int **tab, int y_max, int x_max);
void	debug_affmap(char **tab);

#endif
