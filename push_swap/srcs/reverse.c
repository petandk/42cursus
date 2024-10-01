/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:09:52 by rmanzana          #+#    #+#             */
/*   Updated: 2024/09/30 18:22:07 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_list **lst)
{
	t_list	*head;
	t_list	*last;
	t_list	*prev;

	head = *lst;
	if (head == NULL || head -> next == NULL)
		return ;
	last = ft_lstlast(head);
	prev = last -> prev;
	prev -> next = NULL;
	last -> next = head;
	last -> prev = NULL;
	head -> prev = last;
	*lst = last;
}

void	ft_reverse_both(t_list **a, t_list **b)
{
	ft_reverse(a);
	ft_reverse(b);
}
