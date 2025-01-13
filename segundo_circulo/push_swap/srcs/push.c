/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:15:17 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/07 22:54:29 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*src_head;
	t_stack	*dest_head;
	t_stack	*new_head;

	src_head = *src;
	dest_head = *dest;
	if (src_head == NULL)
		return ;
	new_head = src_head -> next;
	if (new_head)
		new_head->prev = NULL;
	src_head->next = dest_head;
	src_head->prev = NULL;
	if (dest_head)
		dest_head->prev = src_head;
	*src = new_head;
	*dest = src_head;
}

void	pa(t_stack **a, t_stack **b)
{
	ft_push(b, a);
	*a = ft_lstfirstnode(*a);
	*b = ft_lstfirstnode(*b);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	*a = ft_lstfirstnode(*a);
	*b = ft_lstfirstnode(*b);
	ft_printf("pb\n");
}
