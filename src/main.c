#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	all;

	if (ac == 1)
		return (usage("no file"));
	if (ac > 2)
		return (usage("multiple file"));
	if ((check_file(av, &all)) == -1)
		return (error("file"));
	get_infos(av[1], &all);
	ft_putendl("yooyo");
	affiche_tab_debug(all.tab);
	ft_putendl("ererer");
	return (0);
}
