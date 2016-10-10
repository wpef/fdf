/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:35:24 by fde-monc          #+#    #+#             */
/*   Updated: 2016/10/10 19:40:16 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_fdf	all;

	if (ac == 1)
		return (usage("no file"));
	if (ac > 2)
		return (usage("multiple file"));
	if ((check_file(av, &all)) == -1)
		return (error("file"));
	get_infos(av[1], &all);
	run_mlx(&all);
//	debug_list(&all);
	return (0);
}

void	debug_list(t_fdf *all)
{
	t_dot *ptr;
	int i = 0;
	ptr = *all->dots;
	while (ptr != NULL)
	{
		for (i = 0; i < X_MAX; i++)
		{
			ft_putnbr(ptr->x);
			ft_putchar('\t');
			ptr = ptr->next;
		}
		ft_putchar('\n');
		i = 0;
	}
}
