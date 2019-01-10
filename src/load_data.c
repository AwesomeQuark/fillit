/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:05:59 by conoel            #+#    #+#             */
/*   Updated: 2019/01/10 18:37:01 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char	***load_data(int argc, char **argv)
{
	char	***data;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!(data = malloc(sizeof(char **) * 26)))
		return (NULL);
	argc = 0;
	argv[1] = 0;
	return (data);
}