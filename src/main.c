/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:05:58 by conoel            #+#    #+#             */
/*   Updated: 2019/01/11 20:00:43 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		main(int argc, char **argv)
{
	char	**data;

	if (argc != 2)
	{
		write(2, "usage : ./fillit [file name]\n", 29);
		return (0);
	}
	if (!(data = load_data(argv[1])))
	{
		write(1, "error\n", 6);
		return (0);
	}
	//ft_putstr(fillit(data, nb_tetri(data)));
	//ft_free(data);
	return (1);
}
