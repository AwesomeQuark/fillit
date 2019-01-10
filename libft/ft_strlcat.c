/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:40:18 by fguarrac          #+#    #+#             */
/*   Updated: 2018/11/16 12:04:34 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*d;

	i = 0;
	j = ft_strlen(dst);
	d = dst;
	if (j < size)
	{
		while ((i < (size - j - 1)) && (src[i] != '\0'))
		{
			d[j + i] = src[i];
			i++;
		}
		d[j + i] = '\0';
		return (j + ft_strlen(src));
	}
	else
		return (size + ft_strlen(src));
}
