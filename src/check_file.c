#include "fdf.h"

int	check_file(char **av)
{
	int	fd;
	int	y_max;
	char ***tab;

	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	if ((y_max = read_file1(fd)) < 0)
		return (-1);
	close(fd);
	fd = open(av[1], O_RDONLY);
	tab = make_tab(fd, y_max);
	//if ((ab = read_file2(fd)) < 0)
	//	return (-1);
	close(fd);
	return (1);
}

int	read_file1(int fd)
{
	char	*buf;
	int		y_max;

	y_max = 0;
	while (ft_gnl(fd, &buf) > 0)
	{
		if (check_line1(buf) == -1)
		{
			ft_strdel(&buf);
			return (-1);
		}
		ft_strdel(&buf);
		y_max++;
	}
	return (y_max);
}

char	***make_tab(int fd, int y_max)
{
	char	*buf;
	char	***tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * y_max);
	while (ft_gnl(fd, &buf) > 0)
	{
		tab[i] = ft_strsplit(buf, ' ');
		ft_bzero(buf, BUFF_SIZE);
		i++;
	}
	affiche_tab_debug(tab);
	return (tab);
}

void	affiche_tab_debug(char ***tab)
{
	int y = 0;
	int x = 0;

	while (tab[y])
	{
		x = 0;
		while (tab[x] != NULL)
		{
			ft_putstr(tab[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
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
			break ;
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
