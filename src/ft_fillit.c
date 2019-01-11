/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:06:01 by conoel            #+#    #+#             */
/*   Updated: 2019/01/11 19:25:17 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static void		ft_merge()
{

}

static void		ft_remove()
{

}

static int		ft_test_pos(char *ret, int x, int y, char *tetri)
{
	int i;

	i = 0;

}

int				ft_track(char **data, char *ret, int size)
{
	int		i;

	i = 0;
	while (size)
	{
		while (data[i] != NULL)
		{
			if(ft_test_pos(ret, data[i], size) == 1)
			{
				ft_merge(ret, data[i]);
				if (ft_track(data, ret, size) == 1)
					return (1);
			}
			ft_remove(ret, i);
			i++;
		}
		size++;
	}
}
	
char	*ft_fillit(char **data, int size_min)
{
	char ret[(size_min * size_min) + 1];

	ret[size_min * size_min] = '\0';
	ft_track(&data, size_min);
	return (ret);
}
