/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:06:01 by conoel            #+#    #+#             */
/*   Updated: 2019/01/11 21:12:08 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static void		ft_merge(char *ret, char *tetri, int size, int pos)
{
	int i;
	int j;

	i = pos;
	j = 0;
	while (ret[i])
	{
		//if (i % size >= pos && i % size <= pos + 5 && tetri[j] != '.')
		//	ret[i] == tetri[j];
		//i++;
	}
}

static void		ft_remove(char *ret, int tetri_nb)
{
	int i;

	i = 0;
	while (ret[i])
	{
		ret[i] == tetri_nb + 48 ? ret[i] = '.' : 0;
	}
}

static int		ft_test_pos(char *ret, char *tetri, int pos)
{
	int i;

	i = 0;
	while (ret[i])
	{

	}
}

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
}
	
char	*ft_fillit(char **data, int size_min)
{
	char ret[(size_min * size_min) + 1];

	ft_memset(ret, size_min * size_min, '.');
	ft_track(&data, size_min);
	return (ret);
}
