/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:43:55 by conoel            #+#    #+#             */
/*   Updated: 2019/01/12 15:52:01 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	ft_putstr(char *str, int size)
{
	int i;
	int j;

	j = 0;
	i = size;
	while (i--)
	{
		write(1, &str[j], size);
		write(1, "\n", 1);
		j += size;
	}
	return ;
}
