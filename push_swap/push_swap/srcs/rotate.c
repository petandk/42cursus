/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:44:45 by rmanzana          #+#    #+#             */
/*   Updated: 2024/09/30 18:07:21 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **lst)
{
	t_list	*head;
	t_list	*next;
	t_list	*last;

	head = *lst;
	if (head == NULL || head -> next == NULL)
		return ;
	next = head -> next;
	next -> prev = NULL;
	last = ft_lstlast(head);
	head -> prev = last;
	head -> next = NULL;
	last -> next = head;
	*lst = next;
}

void	ft_rotate_both(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
}
