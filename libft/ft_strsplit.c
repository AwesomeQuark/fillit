/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:18:26 by fguarrac          #+#    #+#             */
/*   Updated: 2018/11/28 19:11:50 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		l;
	char	**t;

	if (!s || !(t = (char **)malloc(sizeof(char *) * (ft_cntwrds(s, c) + 1))))
		return (NULL);
	i = 0;
	l = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
		j = i;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			t[l] = ft_strsub(s, j, i - j);
			l++;
		}
	}
	t[l] = NULL;
	return (t);
}
