#include "fdf.h"

void	aff_nbline(int *line, int max)
{
	int i = 0;
	while (i < max)
	{
		ft_putnbr(line[i]);
		ft_putchar('\t');
		i++;
	}
		ft_putchar('\n');
}

void	debug_affmap(char **tab)
{
	int i = 0;

	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

void	affiche_tab_debug(int **tab, int y_max, int x_max)
{
	int y = 0;
	int x = 0;

	ft_putendl("_________ DEBUG _________");
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			ft_putnbr(tab[y][x]);
			ft_putchar('\t');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putendl("_________ EOF DEBUG _________");
}
