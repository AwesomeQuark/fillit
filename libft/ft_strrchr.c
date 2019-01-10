/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:58:02 by fguarrac          #+#    #+#             */
/*   Updated: 2018/11/16 16:48:21 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int t;

	i = 0;
	t = -1;
	while ((unsigned long)i <= ft_strlen(s))
	{
		if (s[i] == (unsigned char)c)
			t = i;
		i++;
	}
	if (t >= 0)
		return (&((char *)s)[t]);
	else
		return (NULL);
}
