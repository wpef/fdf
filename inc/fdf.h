#ifndef FDF_H
# define FDF_H
# include "libft.h"
# define ERROR(ID) (ft_strcmp(ID, id) == 0 ? 1 : 0)
# define BUFF_SIZE 50

int	usage(char *id);
int	error(char *id);

int	check_file(char **av);
int	read_file(int fd);

#endif
