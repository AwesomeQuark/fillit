/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:15:29 by fguarrac          #+#    #+#             */
/*   Updated: 2018/11/16 13:56:44 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if ((unsigned char)c != '\0')
	{
		while (s[i] != '\0')
		{
			if (s[i] == (unsigned char)c)
				return (&((char *)s)[i]);
			i++;
		}
	}
	if ((unsigned char)c == '\0')
	{
		while ((s[i] != '\0') || (s[i] == '\0'))
		{
			if (s[i] == (unsigned char)c)
				return (&((char *)s)[i]);
			i++;
		}
	}
	return (NULL);
}
