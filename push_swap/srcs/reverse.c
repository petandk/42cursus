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

void	ft_reverse(t_stack **lst)
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

void	ft_reverse_both(t_stack **a, t_stack **b)
{
	ft_reverse(a);
	ft_reverse(b);
}
