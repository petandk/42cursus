/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:09:52 by rmanzana          #+#    #+#             */
/*   Updated: 2024/10/01 19:56:47 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse(t_stack **lst)
{
	t_stack	*head;
	t_stack	*last;
	t_stack	*prev;

	head = *lst;
	if (head == NULL || head -> next == NULL)
		return ;
	last = ft_lstlastnode(head);
	prev = last -> prev;
	prev -> next = NULL;
	last -> next = head;
	last -> prev = NULL;
	head -> prev = last;
	*lst = last;
}

void	rra(t_stack **a)
{
	ft_reverse(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	ft_reverse(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_reverse(a);
	ft_reverse(b);
	ft_printf("rrr\n");
}
