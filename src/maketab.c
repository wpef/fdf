/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maketab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:36:47 by fde-monc          #+#    #+#             */
/*   Updated: 2016/10/10 19:43:50 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**make_tab(int fd, int y_max, int x_max)
{
	int	**rest;
	int	y;

	y = 0;
	rest = malloc(sizeof(int) * y_max * x_max);
	while (y_max > 0)
	{
		rest[y] = make_line(fd, x_max);
		y++;
		y_max--;
	}
	close(fd);
	return (rest);
}

int		*make_line(int fd, int x_max)
{
	char **tab;
	char *buf;
	int *res;
	int i;

	i = 0;
	ft_gnl(fd, &buf);
	tab = splitmap(buf, x_max);
	ft_strdel(&buf);
	res = malloc(sizeof(int) * x_max);
	while (tab[i])
	{
		res[i] = ft_atoi(tab[i]);
		i++;
	}
	return (res);
}

char	**splitmap(char *line, int x_max)
{
	int i;
	int strt;
	int len;
	char **tab;

	i = 0;
	strt = 0;
	if (line == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (x_max + 1));
	while (i < x_max)
	{
		while (line[strt] && !ft_isalnum(line[strt]))
			strt++;
		len = 0;
		while (line[strt + len] && ft_isalnum(line[strt + len]))
				len++;
		tab[i] = ft_strsub(line, strt, len);
		strt = strt + len;
		i++;
	}
	tab[x_max] = NULL;
	return (tab);
}
