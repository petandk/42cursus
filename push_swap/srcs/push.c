/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:15:17 by rmanzana          #+#    #+#             */
/*   Updated: 2024/11/14 15:47:26 by rmanzana         ###   ########.fr       */
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
	if (new_head != NULL)
		new_head -> prev = NULL;
	src_head -> next = dest_head;
	if (dest_head != NULL)
		dest_head -> prev = src_head;
	*src = new_head;
	*dest = src_head;
	src_head -> prev = NULL;
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
