/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:05:58 by conoel            #+#    #+#             */
/*   Updated: 2019/01/10 21:58:06 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		main(int argc, char **argv)
{
	char	***data;

	if (argc != 2)
	{
		write(2, "usage : ./fillit [file name]\n", 29);
		return (0);
	}
	if (!(data = load_data(argv[1])))
	{
		write(2, "Failed to load the file\n", 24);
		return (0);
	}
	//ft_putstr(fillit(data));
	free(data);
}