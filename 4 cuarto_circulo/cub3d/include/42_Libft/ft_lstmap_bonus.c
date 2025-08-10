/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:57:32 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/01 08:23:25 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	t_list	*temp;

	new_list = NULL;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
			return (ft_lstclear(&new_list, del), NULL);
		if (!new_list)
		{
			new_list = temp;
			new_elem = new_list;
		}
		else
		{
			new_elem->next = temp;
			new_elem = new_elem->next;
		}
		lst = lst->next;
	}
	return (new_list);
}
