/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:10:48 by conoel            #+#    #+#             */
/*   Updated: 2019/01/13 03:31:22 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int			is_valid(char *buffer)
{
	t_index ind;
	int		count;

	ind.i = 0;
	while (buffer[ind.i] != '\0')
	{
		ind.j = 0;
		count = 0;
		while (ind.j++ < 4)
		{
			ind.k = 0;
			while (ind.k++ < 4)
			{
				if (buffer[ind.i] != '.' && buffer[ind.i] != '#' && buffer[ind.i] != '1')
					return (0);
				buffer[ind.i++] == '#' ? count++ : 0;
			}
			if (buffer[ind.i++] != '\n')
				return (0);
		}
		if ((buffer[ind.i] != '\n' && buffer[ind.i + 1] != '\0') ||
(buffer[ind.i] == '\n' && buffer[++ind.i] == '\0') || count != 4)
			return (0);
	}
	return (1);
}
