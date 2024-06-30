/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:58:57 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/30 20:12:46 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*nodes;
	int		nodescount;

	nodes = lst;
	nodescount = ft_lstsize(nodes);
	while (nodescount > 1)
	{
		nodes = nodes -> next;
		nodescount--;
	}
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
