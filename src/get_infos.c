#include "fdf.h"

int get_pixelpos_x(int x, int y)
{
	if (y > -1)
		return (x);
	return (x);
}

int get_pixelpos_y(int x, int y)
{
	if (x > -1)
		return (y);
	return (y);
}

int		get_infos(char *file, t_fdf *all)
{
	int	fd;

	if (all == NULL)
		return (error("Structure all == NULL"));
	fd = open(file, O_RDONLY);
	all->tab = make_tab(fd, all->y_max, all->x_max);
	all->dots = malloc(sizeof(all));
	get_dots(all);
	all->zoom = 45;
	all->height = -3;
	return (all->tab ? 1 : error("TAB NOT CREATED"));
}

void	get_dots (t_fdf *all)
{
	t_dot	*ptr;
	t_dot	*curs;
	int		x;
	int		y;

	x = 0;
	y = 0;

	*all->dots = make_node(0, 0, all->tab[0][0]);
	x++;
	ptr = *all->dots;
	curs = ptr;
	ptr = ptr->next;
	while (y < Y_MAX)
	{
		if (y > 0)
			x = 0;
		while (x < X_MAX)
		{
			ptr = make_node(x, y, all->tab[y][x]);
			curs->next = ptr;
			ptr = ptr->next;
			curs = curs->next;
			x++;
		}
		y++;
	}
}

t_dot	*make_node(int x, int y, int z)
{
	t_dot *ptr;

	ptr = malloc(sizeof(t_dot));
	ptr->x = get_pixelpos_x(x, y);
	ptr->y = get_pixelpos_y(x, y);
	ptr->z = z;
	ptr->next = NULL;
	return (ptr);
}

