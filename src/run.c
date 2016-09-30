#include "fdf.h"

int run_mlx(t_fdf *all)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "FDF"); //win title might change
	all->mlx = mlx;
	all->win = win;
	print_fdf(all);
	//read_commands(all);
	return (1);
}

void	print_fdf(t_fdf *all)
{
	int	**map;

	map = all->tab;
	affiche_tab_debug(map, all->y_max, all->x_max);
}