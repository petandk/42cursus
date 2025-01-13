/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:04:52 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/01 10:05:01 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastnode;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			lastnode = ft_lstlast(*lst);
			lastnode -> next = new;
		}
	}
}
/*
#include <stdio.h>

int	main(void)
{
	t_list *list = ft_lstnew("not last");
	t_list	*lastnode;
	ft_lstadd_front(&list, ft_lstnew("middle"));
	ft_lstadd_front(&list, ft_lstnew("first"));
	ft_lstadd_back(&list, ft_lstnew("Real last"));
	lastnode = ft_lstlast(list);
	printf("Last node: %s\n", (char *)lastnode -> content);
	return (0);
}
*/
