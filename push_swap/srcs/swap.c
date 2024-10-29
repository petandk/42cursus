/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:51:02 by rmanzana          #+#    #+#             */
/*   Updated: 2024/10/01 19:18:48 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **lst)
{
	t_stack	*head;
	t_stack	*next;
	t_stack	*third;

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

void	sa(t_stack **a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}
