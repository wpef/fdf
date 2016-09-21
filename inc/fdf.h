#ifndef FDF_H
# define FDF_H
# include "libft.h"
# define ERROR(ID) (ft_strcmp(ID, id) == 0 ? 1 : 0)

int	usage(char *id);
int	error(char *id);

#endif
