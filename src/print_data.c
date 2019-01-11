/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:32:32 by conoel            #+#    #+#             */
/*   Updated: 2019/01/11 15:37:05 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/fillit.h"

//POUR LE DEBUG

void	print_data(char ***data)
{
	int j;
	int k;

	j = -1;
	k = -1;
	while (data[++k])
		while (data[k][++j])
			write(1, data[k][j], 5);
}