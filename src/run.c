#include "fdf.h"

int run_mlx(t_fdf *all)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 800, "FDF"); //set win size
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
	t_dot *ptr2;
	t_l l;

	ptr = *all->dots;
	while (ptr->next != NULL)
	{
		if (ptr->y == ptr->next->y)
		{
			set_line(&l, ptr, ptr->next, all);
			printline(&l, all);
		}
		ptr2 = ptr->next;
		while (ptr2 != NULL && ptr2->x != ptr->x)
			ptr2=ptr2->next;
		if (ptr2 && ptr2->y == (ptr->y + 1) && ptr2->x == ptr->x)
		{
			set_line(&l, ptr, ptr2, all);
			printline(&l, all);
		}
		ptr=ptr->next;
	}
}
