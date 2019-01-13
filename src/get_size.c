/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:27:58 by conoel            #+#    #+#             */
/*   Updated: 2019/01/13 02:21:57 by conoel           ###   ########.fr       */
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

static int	ft_count_char(int start, int condition, int decalage, char *tet)
{
	int i;
	int count;

	i = start;
	count = 0;
	while (i < condition)
	{
		if (tet[i] != '.')
		{
			count++;
		}
		if (tet[i] == '.' && i != 0)
			break ;
		i += decalage;
	}
	return (count);
}

int			first_check(char **data, int ret)
{
	int nb_tetri;

	nb_tetri = 0;
	while (data[nb_tetri] != NULL)
	{
		if (ft_count_char(0, 5, 1, data[nb_tetri]) > ret)
			ret = ft_count_char(0, 5, 1, data[nb_tetri]);
		if (ft_count_char(5, 10, 1, data[nb_tetri]) > ret)
			ret = ft_count_char(5, 10, 1, data[nb_tetri]);
		if (ft_count_char(10, 15, 1, data[nb_tetri]) > ret)
			ret = ft_count_char(10, 15, 1, data[nb_tetri]);
		if (ft_count_char(0, 21, 5, data[nb_tetri]) > ret)
			ret = ft_count_char(0, 20, 5, data[nb_tetri]);
		if (ft_count_char(1, 21, 5, data[nb_tetri]) > ret)
			ret = ft_count_char(1, 20, 5, data[nb_tetri]);
		if (ft_count_char(2, 21, 5, data[nb_tetri]) > ret)
			ret = ft_count_char(2, 20, 5, data[nb_tetri]);
		nb_tetri++;
	}
	return (ret);
}

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
	return (ret);
}
