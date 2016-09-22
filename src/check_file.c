#include "fdf.h"

int	check_file(char **av)
{
	int	fd;

	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	if (read_file(fd) < 0)
		return(-1);
	return (1);
}

int	read_file(int fd)
{
	char	*buf;

	buf = ft_strnew(BUFF_SIZE);
	while (ft_gnl(fd, &buf) > 0)
	{
		if (check_line(buf) == -1)
			return (-1);
	}
	return (1);
}

int	check_line(char *line)
{
	int	i;
	
	i = 0;
	while (line[i])
	{
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] == ' ')
			i++; 
	}
}
