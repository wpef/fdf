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
	t_dot *ptr;

	ptr = *all->dots;
	while (ptr->next != NULL)
	{
		if (ptr->y == ptr->next->y)
		{
			set_line;
			drawline;
		}
		ptr=ptr->next;
	}
}

void	print_line(t_dot *og, t_dot *gol, t_fdf *all)
{
	int px;
	float y;
	float dx;
	float dy;

	px = og->x;
	dx = (gol->x - og->x);
	dy = (gol->y - og->y);
	while (px <= gol->x)
	{
		y = og->y + dy * (px - og->x) / dx;
		mlx_pixel_put(all->mlx, all->win, px, y, WHITE);
		px++;
	}
}
