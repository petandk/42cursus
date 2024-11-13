/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:14:05 by rmanzana          #+#    #+#             */
/*   Updated: 2024/11/12 23:15:24 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnewnode(int value)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (newnode)
	{
		newnode -> value = value;
		newnode -> next = NULL;
		newnode -> prev = NULL;
		return (newnode);
	}
	return (NULL);
}

t_stack	*ft_lstlastnode(t_stack *lst)
{
	t_stack	*nodes;

	if (lst == NULL)
		return (NULL);
	nodes = lst;
	while (nodes -> next != NULL)
		nodes = nodes -> next;
	return (nodes);
}

t_stack	*ft_lstfirstnode(t_stack *lst)
{
	t_stack	*nodes;

	if (lst == NULL)
		return (NULL);
	nodes = lst;
	while (nodes -> prev != NULL)
		nodes = nodes -> prev;
	return (nodes);
}

void	ft_lstadd_backnode(t_stack **lst, t_stack *new)
{
	t_stack	*lastnode;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			lastnode = ft_lstlastnode(*lst);
			lastnode -> next = new;
			new -> prev = lastnode;
		}
	}
}

int	ft_countnodes(t_stack *lst)
{
	t_stack *list;
	int		i;

	list = ft_lstfirstnode(lst);
	i = 0;
	while (list != NULL)
	{
		i++;
		list = list -> next;
	}
	return (i);
}
