/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:13:48 by fguarrac          #+#    #+#             */
/*   Updated: 2018/11/27 18:10:44 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_lstprint(t_list *lst)
{
	int i;

	while (lst)
	{
		i = 0;
		while (((unsigned char *)lst->content)[i])
			i++;
		write(1, lst->content, i);
		write(1, "\n", 1);
		lst = lst->next;
	}
}
