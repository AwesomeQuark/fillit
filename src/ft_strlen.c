/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:32:59 by conoel            #+#    #+#             */
/*   Updated: 2019/01/10 21:44:14 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*size_t		ft_strlen(char *s)
{
	char *s1;

	s1 = s;
	while (*s)
		s++;
	return(s - s1);
}*/

size_t		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(*s++)
		i++;
	return(i);
}