#include "fdf.h"

t_fdf	get_infos(char *file, int x_max)
{
	t_fdf ret;
	char	*buf;
	int		fd;
	int		y;

	ret.x_max = x_max;
	ret.y_max = 0;
	y = 1;
	fd = open(file, O_RDONLY);
	while (ft_gnl(fd, &buf) > 0)
		ret.y_max++;
	close(fd);
	fd = open(file, O_RDONLY);
	while (ft_gnl(fd, &buf))
	{
		ret.dots = make_list(buf, y);
		y++;
	}
	close(fd);
	return (ret);
}

t_dots	*make_list(char *line, int y)
{
	t_dots	*ret;
	char	**tab;
	int		i;
	t_dots	*ptr;
	t_dots *ptr2;

	tab = ft_strsplit(line, ' ');
	i = 0;
	ret = make_node(tab[i], i, y);
	ptr = ret;
	ptr2 = ret;
	ptr = ptr->next;
	i++;
	while (tab[i])
	{
		ptr = make_node(tab[i], i, y);
		ptr2->next = ptr;
		ptr = ptr->next;
		ptr2 = ptr2->next;
		i++;
	}
	return (ret);
}

t_dots	*make_node(char *dot, int x, int y)
{
	t_dots	*node;

	node = malloc(sizeof(t_dots));
	node->x = x;
	node->y = y;
	node->z = ft_atoi(dot);
	node->next = NULL;
	return (node);
}
