/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:38:59 by fguarrac          #+#    #+#             */
/*   Updated: 2018/11/28 18:55:34 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		l;
	char	*r;

	if (!s)
		return (NULL);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && (s[i] != '\0'))
		i++;
	j = i;
	while (s[i] != '\0')
		i++;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\0')
				&& (i != 0))
		i--;
	l = i;
	if (l == 0)
		return (ft_strnew(1));
	if (!(r = (char *)malloc(sizeof(char) * (l - j))))
		return (NULL);
	r = ft_strsub(s, j, (l - j + 1));
	return (r);
}
