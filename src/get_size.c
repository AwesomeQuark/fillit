/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:27:58 by conoel            #+#    #+#             */
/*   Updated: 2019/01/12 20:01:01 by conoel           ###   ########.fr       */
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

int			first_check(char **data, int ret)
{
	int nb_tetri;
	int count1;
	int count2;
	int i;

	nb_tetri = 0;
	while (data[nb_tetri] != NULL)
	{
		i = 0;
		count1 = 0;
		count2 = 0;
		while (i < 5)
		{
			if (data[nb_tetri][i] != '.')
			{
				count1++;
			}
			if (data[nb_tetri][i] == '.' && i != 0)
				break;
			i++;
		}
		i = 0;
		while (i < 21)
		{
			if (data[nb_tetri][i] != '.')
			{
				count2++;
			}
			if (data[nb_tetri][i] == '.' && i != 0)
				break;
			i += 5;
		}
		if (count1 > ret)
			ret = count1;
		if (count2 > ret)
			ret = count2;
		nb_tetri++;
	}
		return (ret);
}

/*
int			sec_check(char **data, int ret)
{
	`
	return (ret);
}*/

int			get_size(char **data)
{
	int		nb_tetri;
	int		ret;
	int		i;
	int		j;

	nb_tetri = 0;
	while (data[nb_tetri] != NULL)
		nb_tetri++;
	ret = square(nb_tetri * 4);
	ret = first_check(data, ret);
	//ret = sec_check(data, ret);
	return (ret);
}
