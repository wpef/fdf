#include "fdf.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		return (usage("no file"));
	if (ac > 1)
		return (usage("multiple file"));
	if (check_file(av) == -1)
		return (error("file"));
	return (0);
}
