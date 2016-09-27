#include "fdf.h"

int	get_infos(char *file, t_fdf *all)
{
	int	fd;

	if (all == NULL)
		return (error("Structure all == NULL"));
	fd = open(file, O_RDONLY);
	all->tab = make_tab(fd, all->y_max, all->x_max);
	return (all->tab ? 1 : error("TAB NOT CREATED"));
}
