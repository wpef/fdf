/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:34:40 by fde-monc          #+#    #+#             */
/*   Updated: 2016/10/17 15:08:42 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	aff_nbline(int *line, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		ft_putnbr(line[i]);
		ft_putchar('\t');
		i++;
	}
	ft_putchar('\n');
}

void	debug_affmap(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

void	affiche_tab_debug(int **tab, int y_max, int x_max)
{
	int y;
	int x;

	y = 0;
	x = 0;
	ft_putendl("_________ DEBUG _________");
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			ft_putnbr(tab[y][x]);
			ft_putchar('\t');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putendl("_________ EOF DEBUG _________");
}
