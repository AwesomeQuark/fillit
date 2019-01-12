/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_visual.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:31:09 by conoel            #+#    #+#             */
/*   Updated: 2019/01/12 19:38:51 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static void		ft_merge(char *ret, char *tetri, int size, int pos)
{
	int i;
	int j;

	i = pos;
	while (ret[i])
	{
		if (i / size >= pos / size && i % size >= pos % size)
			j = ((i / size - pos / size) * 5) + (i % size - pos % size);
		if (i % size >= (pos % size) && i % size <= (pos % size) + 4 && i / size >= (pos / size) && i / size <= (pos / size) + 4 && j < 20 && tetri[j] >= 'A' && tetri[j] <= 'Z')
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
		if (ret[i] == tetri_nb + 65)
			ret[i] = '.';
		i++;
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
		if (i % size >= (pos % size) && i % size <= (pos % size) + 4 && i / size >= (pos / size) && i / size <= (pos / size) + 4 && tetri[j] >= 'A' && tetri[j] <= 'Z')
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

int				ft_track(char **data, char *ret, int size, int tetri_i, int pos)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_putstr(ret, size);
	usleep(10000);
	if (data[tetri_i] == NULL)
		return (1);
	if (pos >= size * size)
		return (0);
	if (ft_test_pos(ret, data[tetri_i], size, pos))
	{
		ft_merge(ret, data[tetri_i], size, pos);
		if (ft_track(data, ret, size, tetri_i + 1, 0) == 1)
			return (1);
		ft_remove(ret, tetri_i);
	}
	if (ft_track(data, ret, size, tetri_i, pos + 1) == 1)
		return (1);
	return (0);
}
	
void			ft_fillit(char **data, int size_min)
{
	char ret[(size_min * size_min) + 1];

	ft_memset(ret, size_min * size_min , '.');
	ft_track(data, ret, size_min, 0, 0);
	ft_putstr(ret, size_min);
}
