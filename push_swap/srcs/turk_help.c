/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:06:18 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/08 20:59:14 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_smallest_node(t_stack *stack)
{
	t_stack	*smallest;

	if (stack == NULL)
		return (NULL);
	smallest = stack;
	while (stack != NULL)
	{
		if (stack->value < smallest->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

void	final_sort(t_stack **a)
{
	t_stack	*smallest_node;
	int		pos;
	int		size;

	while (1)
	{
		get_position(*a);
		smallest_node = find_smallest_node(*a);
		pos = smallest_node->position;
		size = ft_countnodes(*a);
		if (pos == 0)
			break ;
		if (pos <= size / 2)
			ra(a);
		else
			rra(a);
	}
}

int	get_mid(int mid)
{
	if (mid % 2 == 1)
		mid--;
	return (mid / 2);
}

void	get_cost_returning(t_data *data)
{
	t_stack	*current;
	int		size_a;
	int		size_b;

	size_a = ft_countnodes(data->a);
	size_b = ft_countnodes(data->b);
	current = data->b;
	while (current)
	{
		if (current->target)
		{
			current->cost_b = current->position;
			if (current->position > get_mid(size_b))
				current->cost_b = -(size_b - current->position);
			if (current->target->position > get_mid(size_a))
				current->cost_a = -(size_a - current->target->position);
			else
				current->cost_a = current->target->position;
		}
		current = current->next;
	}
}
