#include "fdf.h"

int		get_infos(char *file, t_fdf *all)
{
	int	fd;

	if (all == NULL)
		return (error("Structure all == NULL"));
	fd = open(file, O_RDONLY);
	all->tab = make_tab(fd, all->y_max, all->x_max);
	all->dots = get_dots(all);
	return (all->tab ? 1 : error("TAB NOT CREATED"));
}

t_dot	**get_dots (t_fdf *all)
{
	t_dot	**ret;
	t_dot	*ptr;
	int		x;
	int		y;

	x = 0;
	y = 0;

	&ret = init_list(all);
	ptr = *ret;
	ptr = ptr->next;
	while (y < Y_MAX)
	{
		while (x < X_MAX)
		{
			make_node(x, y, );
			x++;
		}
		y++;
	}
}

t_dot *init_list (t_fdf *all)
{
	t_dot *ret;

	if (ret = malloc(sizeof(t_dot)) == NULL)
		return (error("Memory allocation failed !"));
	ret->x = get_pixelpos_x(0, 0, all->tab[0][0]);
	ret->y = get_pixelpos_y(0, 0, all->tab[0][0]);
	ret->next = NULL;
	return (ret);
}