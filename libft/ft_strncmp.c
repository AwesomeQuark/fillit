/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:17:33 by fguarrac          #+#    #+#             */
/*   Updated: 2018/11/17 17:17:35 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while ((((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]) &&
		(i < (n - 1)) && (((unsigned char *)s1)[i] != '\0' ||
			((unsigned char *)s2)[i] != '\0'))
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
