/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charindex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:10:04 by fde-monc          #+#    #+#             */
/*   Updated: 2016/03/06 15:10:31 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charindex(char *s, char c)
{
	int i;

	i = 0;
	if (!s)
		return (-2);
	else
	{
		while ((s[i] != '\0') && (s[i] != c))
			i++;
		if (s[i] == c)
			return (i);
	}
	return (-1);
}
