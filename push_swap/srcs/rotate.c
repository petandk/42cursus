/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:44:45 by rmanzana          #+#    #+#             */
/*   Updated: 2024/10/01 19:56:27 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **lst)
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

void	ft_rotate_both(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
}
