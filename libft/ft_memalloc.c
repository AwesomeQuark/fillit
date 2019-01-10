/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:00:23 by fguarrac          #+#    #+#             */
/*   Updated: 2018/11/19 18:24:10 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char *s;

	if (!(s = (unsigned char *)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
