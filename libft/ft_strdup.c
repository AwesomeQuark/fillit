/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:00:15 by fguarrac          #+#    #+#             */
/*   Updated: 2018/12/06 19:21:34 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*s2;

	l = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * ((ft_strlen(s1)) + 1))))
		return (0);
	l = 0;
	while (s1[l] != '\0')
	{
		s2[l] = s1[l];
		l++;
	}
	s2[l] = 0;
	return (s2);
}
