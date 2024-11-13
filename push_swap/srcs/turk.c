/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:00:26 by rmanzana          #+#    #+#             */
/*   Updated: 2024/11/13 00:55:30 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_4(t_stack *stack)
{
	t_stack *nodes_a;
	t_stack *nodes_b;

	nodes_a = ft_lstfirstnode(stack);
	nodes_b = NULL;
	print_single(nodes_a);
	pb(&nodes_a, &nodes_b);
	print_single(nodes_a);
	order_3(nodes_a);
	while (nodes_b && nodes_a && nodes_b -> value > nodes_a -> value)
	{
		ra(&nodes_a);
		nodes_a = ft_lstfirstnode(nodes_a);
	}
	print_single(nodes_a);
	pa(&nodes_a, &nodes_b);
	print_single(nodes_a);
	while (nodes_a && ft_lstlastnode(nodes_a) &&\
			nodes_a -> value > ft_lstlastnode(nodes_a)-> value)
	{
		rra(&nodes_a);
		nodes_a = ft_lstfirstnode(nodes_a);
	}
	nodes_a = ft_lstfirstnode(nodes_a);
	nodes_b = ft_lstfirstnode(nodes_b);
	print_single(nodes_a);
}
/*
void	turk(t_stack *stack)
{
	t_stack	*nodes_b;

	nodes_b = NULL;
}
*/
