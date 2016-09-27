#include "fdf.h"

int	**make_tab(int fd, int y_max, int x_max)
{
	int	**rest;
	int	y;

	y = 0;
	rest = malloc(sizeof(int) * y_max * x_max);
	while (y_max > 0)
	{
		rest[y] = make_line(fd, x_max);
		y++;
		y_max--;
	}
	close(fd);
	return (rest);
}

int	*make_line(int fd, int x_max)
{
	char **tab;
	char *buf;
	int *res;
	int i;

	i = 0;
	ft_gnl(fd, &buf);
	tab = ft_strsplit(buf, ' ');
	ft_strdel(&buf);
	res = malloc(sizeof(int) * x_max);
	while (tab[i])
	{
		res[i] = ft_atoi(tab[i]);
		i++;
	}
	return (res);
}

void	affiche_tab_debug(int **tab)
{
	int y = 0;
	int x = 0;

	if (tab)
		ft_putendl("AFUG");
	if (tab[y])
		ft_putendl("AFUG");
	if (tab[y][x])
		ft_putendl("AFUG");
	ft_putendl("INSIDE MAMEN");
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			ft_putnbr(tab[y][x]);
		ft_putchar('\t');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
