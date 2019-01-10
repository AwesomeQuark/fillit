/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:12:02 by fguarrac          #+#    #+#             */
/*   Updated: 2018/11/28 19:07:00 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !f)
		return (NULL);
	tmp = NULL;
	tmp2 = NULL;
	if (lst->next)
		tmp = ft_lstmap(lst->next, f);
	if (!(tmp2 = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	tmp2 = (f(lst));
	tmp2->next = tmp;
	tmp = tmp2;
	return (tmp);
}
