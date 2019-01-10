/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:17:51 by fguarrac          #+#    #+#             */
/*   Updated: 2018/11/28 16:47:07 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (needle[0] == '\0')
		return (&((char *)haystack)[i]);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while ((haystack[i] != needle[j]) && (haystack[i] != '\0') && i < len)
		{
			i++;
			if (haystack[i] == '\0' || i == len)
				return (NULL);
		}
		while ((haystack[i + j] == needle[j])
				&& (haystack[i + j] != '\0') && (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
