/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:14:05 by rmanzana          #+#    #+#             */
/*   Updated: 2024/09/30 16:19:48 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (newnode)
	{
		newnode -> value = value;
		newnode -> next = NULL;
		newnode -> prev = NULL;
		return (newnode);
	}
	return (NULL);
}

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

t_list	*ft_lstfirst(t_list *lst)
{
	t_list	*nodes;

	if (lst == NULL)
		return (NULL);
	nodes = lst;
	while (nodes -> prev != NULL)
		nodes = nodes -> prev;
	return (nodes);
}

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
			new -> prev = lastnode;
		}
	}
}
