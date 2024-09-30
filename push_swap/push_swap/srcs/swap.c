/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:51:02 by rmanzana          #+#    #+#             */
/*   Updated: 2024/09/30 18:19:11 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **lst)
{
	t_list	*head;
	t_list	*next;
	t_list	*third;

	head = *lst;
	if (head == NULL || head -> next == NULL)
		return ;
	next = head -> next;
	head -> next = next -> next;
	next -> next = head;
	head -> prev = next;
	next -> prev = NULL;
	if (head -> next != NULL)
	{
		third = head -> next;
		third -> prev = head;
	}
	*lst = next;
}

void	ft_swap_both(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
}
