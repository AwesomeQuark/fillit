/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_visual.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 05:27:17 by conoel            #+#    #+#             */
/*   Updated: 2019/01/13 06:04:05 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_merge(char *ret, char *tetri, int size, int pos)
{
	int i;

	i = 0;
	while (tetri[i])
	{
		if (tetri[i] != '.')
		{
			ret[(pos + (i % 5)) + (i / 5) * size] = tetri[i];
		}
		i++;
	}
}

static int		ft_test_pos(char *ret, char *tetri, int size, int pos)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (tetri[i] && count < 4)
	{
		if (tetri[i] != '.')
		{
			if (ret[(pos + (i % 5)) + (i / 5) * size] == '.' &&
(pos % size) + (i % 5) < size)
				count++;
			else
				return (0);
		}
		i++;
	}
	return (count == 4 ? 1 : 0);
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

int				ft_track(t_data arg, int size, int tetri_i, int pos)
{
	ft_putstr_visual(arg.ret, size);
	usleep(20000);
	if (arg.data[tetri_i] == NULL)
		return (1);
	if (pos >= size * size)
		return (0);
	if (ft_test_pos(arg.ret, arg.data[tetri_i], size, pos))
	{
		ft_merge(arg.ret, arg.data[tetri_i], size, pos);
		if (ft_track(arg, size, tetri_i + 1, 0) == 1)
			return (1);
		ft_remove(arg.ret, tetri_i);
	}
	if (ft_track(arg, size, tetri_i, pos + 1) == 1)
		return (1);
	return (0);
}

void			ft_fillit(char **data, int size_min)
{
	char	ret[(size_min + 1) * (size_min + 1) + 1];
	t_data	arguments;

	arguments.data = data;
	arguments.ret = ret;
	ft_memset(arguments.ret, size_min * size_min, '.');
	while (ft_track(arguments, size_min, 0, 0) == 0)
	{
		size_min++;
		ft_memset(arguments.ret, size_min * size_min, '.');
	}
	ft_putstr(ret, size_min);
}
