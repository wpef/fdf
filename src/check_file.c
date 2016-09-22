#include "fdf.h"

int	check_file(char **av)
{
	int	fd;

	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	if (read_file1(fd) < 0)
		return(-1);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (read_file2(fd) < 0)
		return (-1);
	return (1);
}

int	read_file1(int fd)
{
	char	*buf;

	while (ft_gnl(fd, &buf) > 0)
	{
		if (check_line1(buf) == -1)
		{
			ft_strdel(&buf);
			return (-1);
		}
		ft_strdel(&buf);
	}
	return (1);
}

int	check_line1(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] != ' ')
			break;
		i++;
	}
	if (i == ft_strlen(line))
		return (1);
	return (-1);
}

int	read_file2(int fd)
{
	int		ab;
	char	*buf;

	ft_gnl(fd, &buf);
	ab = check_line2(buf);
	ft_strdel(&buf);
	while (ft_gnl(fd, &buf) > 0)
	{
		if (check_line2(buf) != ab)
		{
			ft_strdel(&buf);
			return (-1);
		}
		ft_strdel(&buf);
	}
	return (1);
}

int	check_line2(char *line)
{
	size_t	i;
	int		ab;

	i = 0;
	ab = 0;
	while (i < ft_strlen(line))
	{
		if (ft_isdigit(line[i]))
		{
			ab++;
			while (ft_isdigit(line[i]))
				i++;
		}
		i++;
	}
	return (ab);
}
