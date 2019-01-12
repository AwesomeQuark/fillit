/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:27:58 by conoel            #+#    #+#             */
/*   Updated: 2019/01/12 14:25:39 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static int	square(int nb)
{
	int		sqr;

	sqr = 1;
	while (nb > sqr * sqr)
		sqr++;
	return (sqr);
}

int			get_size(char **data)
{
	int		nb_tetri;
	int		ret;

	nb_tetri = 0;
	while (data[nb_tetri] != NULL)
		nb_tetri++;
	ret = square(nb_tetri * 4);
	return (ret < 4 ? 4 : ret);
}
