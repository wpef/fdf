/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:34:44 by fde-monc          #+#    #+#             */
/*   Updated: 2016/10/10 19:40:41 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	usage(char *id)
{
	ft_putstr_fd("fdf: ", STDERR_FILENO);
	if (ERROR("no file"))
		ft_putendl_fd("No file turned in", STDERR_FILENO);
	if (ERROR("multiple file"))
		ft_putendl_fd("Multiple files turned in", STDERR_FILENO);
	ft_putendl_fd("usage:\t./fdf [file1]", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	error(char *id)
{
	ft_putstr_fd("fdf: error\nError: ", STDERR_FILENO);
	if (ERROR("file"))
		ft_putendl_fd("Invalid file", STDERR_FILENO);
	else
		ft_putendl_fd(id, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
