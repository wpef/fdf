#include "fdf.h"

int run_mlx(t_fdf *all)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 800, "FDF"); //set win size
	all->mlx = mlx;
	all->win = win;
	all->x_og = 100;
	all->y_og = 80;
	print_fdf(all);
	read_commands(all);
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

int		read_commands(t_fdf *all)
{
	mlx_key_hook(all->win, keypress, all);
	return (1);
}

int		keypress(int keycode, void *all)
{
	if (!all)
		error("key hook crashed");
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode >= 123 && keycode <= 126)
	{
		move_og(keycode, all);
		print_fdf(all);
	}
	printf("KEY = %d\n", keycode);
	return (1);
}

int		move_og(int keycode, t_fdf *all)
{
	if (keycode == 126)
		all->x_og = all->x_og + 10;
	else if (keycode == 123)
		all->y_og = all->y_og - 10;
	else if (keycode == 125)
		all->x_og = all->x_og - 10;
	else
		all->y_og = all->y_og + 10;
	return (1);
}
