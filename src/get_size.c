/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:27:58 by conoel            #+#    #+#             */
/*   Updated: 2019/01/12 19:45:18 by fguarrac         ###   ########.fr       */
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
	nb_tetri = 0;
	while (data[nb_tetri] != NULL)
	{
		i = 0;
		j = 0;
		while (data[nb_tetri][i] != '\0' && data[nb_tetri[i] == '.'])
		{
			i++;
			while (data[nb_tetri][i] != '.' && data[nb_tetri[i] != '\0'])
				i++;
			if (i > ret)
				ret++;
			i += 4;
			if (data[nb_tetri][i] != '.')
				j++;
		}
		if (j > ret)
			ret++;
		nb_tetri++;
	}
		return (ret);
}

int			sec_check(char **data, int ret)
{
	`
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
	ret = sec_check(data, ret);
	return (ret);
}
