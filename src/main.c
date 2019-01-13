/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:05:58 by conoel            #+#    #+#             */
/*   Updated: 2019/01/13 03:57:33 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	ft_fillit(data, get_size(data));
	ft_free(data);
	return (1);
}
