/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:06:01 by conoel            #+#    #+#             */
/*   Updated: 2019/01/12 15:58:06 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static void		ft_merge(char *ret, char *tetri, int size, int pos)
{
	int i;
	int j;

	i = pos;
	while (ret[i] && tetri[j])
	{
		if (i / size >= pos / size && i % size >= pos % size)
			j = ((i / size - pos / size) * 5) + (i % size - pos % size);
		if (i % size >= (pos % size) && i % size <= (pos % size) + 4 && i / size >= (pos / size) && i / size <= (pos / size) + 4 && tetri[j])
		{
			if (tetri[j] != '.')
				ret[i] = tetri[j];
		}
		i++;
	}
}

static void		ft_remove(char *ret, int tetri_nb)
{
	int i;

	i = 0;
	while (ret[i])
	{
		if (ret[i] == tetri_nb + 48)
			ret[i] = '.';
	}
}

static int		ft_test_pos(char *ret, char *tetri, int size, int pos)
{
	int i;
	int j;
	int count;

	i = pos;
	count = 0;
	while (ret[i])
	{
		if (i / size >= pos / size && i % size >= pos % size)
			j = ((i / size - pos / size) * 5) + (i % size - pos % size);
		if (i % size >= (pos % size) && i % size <= (pos % size) + 4 && i / size >= (pos / size) && i / size <= (pos / size) + 4 && tetri[j] != '.' && tetri[j])
		{
			if (ret[i] == '.')
				count++;
			else
				return (0);
		}
		i++;
	}
	return (count == 4 ? 1 : 0);
}
/*
int				ft_track(char **data, char *ret, int size, int tetri_i)
{
	int		pos;

	pos = 0;
	while (size)
	{
		while (data[tetri_i] != NULL)
		{
			while (pos)
			{
				if(ft_test_pos(ret, data[tetri_i], size, pos) == 1)
				{
					ft_merge(ret, data[tetri_i], size, pos);
					if (ft_track(data, ret, size, tetri_i + 1) == 1)
						return (1);
				}
				ft_remove(ret, tetri_i);
			}
			tetri_i++;
		}
		size++;
	}
	return (0);
}*/
	
void			ft_fillit(char **data, int size_min)
{
	char ret[(size_min * size_min) + 1];

	ft_memset(ret, size_min * size_min , '.');
	//ft_track(&data, size_min);
	//ft_merge(ret, data[0], size_min, 57);
	ft_merge(ret, data[1], size_min, 10);
	//printf("%d\n", ft_test_pos(ret, data[1], size_min, 57));
	ft_putstr(ret, size_min);
}
