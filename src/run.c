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
	mlx_loop(mlx);
	return (1);
}


void	print_fdf(t_fdf *all)
{
	int	**map;
	int y;

	y = 0;
	map = all->tab;
	while (y < all->y_max)
	{
		print_line(map[y], y, all);
		y++;
	}

}

void	print_line(int *line, int y, t_fdf *all)
{
	
}