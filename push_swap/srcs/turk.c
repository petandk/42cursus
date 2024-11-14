/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:00:26 by rmanzana          #+#    #+#             */
/*   Updated: 2024/11/14 17:14:16 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest(t_stack *stack)
{
	int		smallest;
	int		pos;
	int		current_pos;
	t_stack	*current;

	smallest = stack -> value;
	pos = 0;
	current_pos = 0;
	current = stack;

	while (current)
	{
		if (current -> value < smallest)
		{
			smallest = current -> value;
			pos = current_pos;
		}
		current = current -> next;
		current_pos++;
	}
	return (pos);
}

void	order_4(t_stack *stack)
{
	t_stack	*nodes_a;
	t_stack	*nodes_b;
	int		smallest_pos;

	nodes_a = ft_lstfirstnode(stack);
	nodes_b = NULL;
	smallest_pos = find_smallest(nodes_a);
	if (smallest_pos == 1)
		sa(&nodes_a);
	else if (smallest_pos == 2)
	{
		ra(&nodes_a);
		ra(&nodes_a);
	}
	else if (smallest_pos == 3)
		rra(&nodes_a);
	pb(&nodes_a, &nodes_b);
	order_3(nodes_a);
	nodes_a = ft_lstfirstnode(nodes_a);
	pa(&nodes_a, &nodes_b);
	print_single(nodes_a);
}
/*
void	turk(t_stack *stack)
{
	t_stack	*nodes_b;

	nodes_b = NULL;
}
*/
