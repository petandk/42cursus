/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:05:45 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/01 15:03:39 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*nodes;

	if (lst == NULL)
		return (NULL);
	nodes = lst;
	while (nodes -> next != NULL)
		nodes = nodes -> next;
	return (nodes);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list *list = ft_lstnew("last");
	t_list	*lastnode;
	ft_lstadd_front(&list, ft_lstnew("middle"));
	ft_lstadd_front(&list, ft_lstnew("first"));
	lastnode = ft_lstlast(list);
	printf("Last node: %s\n", (char *)lastnode -> content);
	return (0);
}
*/
