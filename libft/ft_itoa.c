/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:16:17 by fguarrac          #+#    #+#             */
/*   Updated: 2018/11/28 13:01:20 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_chck(int *n, int *i, int *k)
{
	int j;

	if (*n == 0)
		(*i)++;
	if (*n < 0)
	{
		*n = -(*n);
		*k = -(*k);
		(*i)++;
	}
	j = *n;
	while (j > 0)
	{
		j = j / 10;
		(*i)++;
	}
}

char			*ft_itoa(int n)
{
	int		i;
	int		k;
	char	*r;

	i = 0;
	k = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_chck(&n, &i, &k);
	if (!(r = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	r[i] = '\0';
	while (i--)
	{
		r[i] = ((n % 10) + 48);
		n /= 10;
	}
	if (k < 0)
		r[0] = 45;
	return (r);
}
