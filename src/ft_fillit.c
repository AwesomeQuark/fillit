/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:06:01 by conoel            #+#    #+#             */
/*   Updated: 2019/01/11 18:55:24 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		ft_test_pos(char *ret, int x, int y, char *tetri)
{
	int i;

	i = 0;
	while (tetri[i] != '.' && tetri[i] != '\n')
		i++;
	while ()
}

void		ft_track(**data[i], *ret, int nb_tetri)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (data[i] != NULL)
	{
		x = 0;
		while (x <= size_min) //position x
		{
			y = 0;
			while (y <= size_min) //position y
			{
				if(ft_test_pos(&ret, x, y, &data[i][0]) == 1)
				{
					//placer
					if (ft_track(**data[i + 1], *ret, int size_min) == 1) //place libre
						break ;
				}
				//supprimer
				y++;
			}
			x++;
		}
		i++;
	}
}
	
char	*ft_fillit(char **data, int size_min)
{
	char ret[(size_min * size_min) + 1];

	ret[size_min * size_min] = '\0';
	ft_track(&data, size_min);
	return (ret);
}
