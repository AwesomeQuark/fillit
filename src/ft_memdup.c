/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:51:38 by conoel            #+#    #+#             */
/*   Updated: 2019/01/11 16:35:18 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char	*ft_memdup(char *str, size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (size == 0)
		return (NULL);
	if (!(ret = malloc(sizeof(*ret) * size + 1)))
		return (NULL);
	while (size--)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
