/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:44:45 by rmanzana          #+#    #+#             */
/*   Updated: 2024/11/14 16:02:12 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **lst)
{
	t_stack	*head;
	t_stack	*next;
	t_stack	*last;

	head = *lst;
	if (head == NULL || head -> next == NULL)
		return ;
	next = head -> next;
	next -> prev = NULL;
	last = ft_lstlastnode(head);
	head -> prev = last;
	head -> next = NULL;
	last -> next = head;
	*lst = next;
}

void	ra(t_stack **a)
{
	ft_rotate(a);
	*a = ft_lstfirstnode(*a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	ft_rotate(b);
	*b = ft_lstfirstnode(*b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	*a = ft_lstfirstnode(*a);
	*b = ft_lstfirstnode(*b);
	ft_printf("rr\n");
}
