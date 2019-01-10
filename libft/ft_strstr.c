/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:10:12 by fguarrac          #+#    #+#             */
/*   Updated: 2018/11/28 15:56:47 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (needle[0] == '\0')
		return (&((char *)haystack)[i]);
	while (haystack[i] != '\0')
	{
		j = 0;
		while ((haystack[i] != needle[j]) && (haystack[i] != '\0'))
		{
			i++;
			if (haystack[i] == '\0')
				return (NULL);
		}
		while ((haystack[i + j] == needle[j]) && (haystack[i + j] != '\0'))
			j++;
		if (needle[j] == '\0')
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
