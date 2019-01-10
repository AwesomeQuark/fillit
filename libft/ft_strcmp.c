/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:14:57 by fguarrac          #+#    #+#             */
/*   Updated: 2018/11/19 18:07:40 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while ((((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]) &&
			(((unsigned char *)s1)[i] != '\0' ||
				(((unsigned char *)s2)[i] != '\0')))
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
