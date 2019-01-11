/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:23:48 by fguarrac          #+#    #+#             */
/*   Updated: 2019/01/11 17:36:17 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	ft_free(char **data)
{
	int i;
	int j;

	i = 0;
	while (data[i] != NULL)
	{
		j = 0;
		free(data[i]);
		i++;
	}
	free(data[i]);
	free(data);
}
