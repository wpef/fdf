#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;
	int		x_max;

	if (ac == 1)
		return (usage("no file"));
	if (ac > 2)
		return (usage("multiple file"));
	if ((x_max = check_file(av)) == -1)
		return (error("file"));
	fdf = get_infos(av[1], x_max);
	ft_idebug("NB LINES == %", fdf.y_max);
	return (0);
}
