/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:36:52 by fde-monc          #+#    #+#             */
/*   Updated: 2016/10/10 19:43:07 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	set_line(t_l *l, t_dot *og, t_dot *gol, t_fdf *all)
{
	l->x = ((og->x * all->zoom) + (og->z * all->height) + all->x_og);
	l->y = ((og->y * all->zoom) + (og->z * all->height) + all->y_og);
	l->xd = (((gol->x * all->zoom) + (gol->z * all->height) + all->x_og)
			- (l->x));
	l->yd = (((gol->y * all->zoom) + (gol->z * all->height) + all->y_og)
			- (l->y + 1));
	return (1);
}

int	printline(t_l *l, t_fdf *all)
{
	int		x;
	int		y;
	double	coef;

	x = 0;
	y = 0;
	coef = 0.0;
	while (coef <= 1)
	{
		x = l->x + (l->xd * coef);
		y = l->y + (l->yd * coef);
		mlx_pixel_put(all->mlx, all->win, x, y, WHITE);
		coef += 1 / (sqrt((l->xd * l->xd) + (l->yd * l->yd)));
	}
	return (1);
}

int	print_std(t_l *l, t_fdf *all)
{
	int	i;

	i = 0;
	if (l->xd == 0)
	{
		while (i <= l->yd)
		{
			mlx_pixel_put(all->mlx, all->win, l->x, l->y + i, WHITE);
			i < l->yd ? i++ : i--;
		}
	}
	else if (l->yd == 0)
	{
		while (i <= l->xd)
		{
			mlx_pixel_put(all->mlx, all->win, l->x + i, l->y, WHITE);
			i < l->xd ? i++ : i--;
		}
	}
	return (1);
}
