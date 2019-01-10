/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:01:02 by fguarrac          #+#    #+#             */
/*   Updated: 2018/11/19 19:07:56 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	unsigned char *buf;

	if (!(buf = (unsigned char *)malloc(sizeof(unsigned char) * (size + 1))))
		return (NULL);
	ft_memset(buf, '\0', (size + 1));
	return ((char *)buf);
}
