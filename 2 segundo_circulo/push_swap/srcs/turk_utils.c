/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:03:40 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/08 20:58:04 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_stack	*find_b_target(t_stack *a_node, t_stack *stack_b)
{
	t_stack	*target;
	t_stack	*current;

	target = NULL;
	current = stack_b;
	while (current)
	{
		if (current->value < a_node->value
			&& (!target || current->value > target->value))
			target = current;
		current = current->next;
	}
	if (!target)
		target = find_biggest(stack_b);
	return (target);
}

void	find_b_targets(t_data *data)
{
	t_stack	*current;

	current = data->a;
	while (current)
	{
		current->target = find_b_target(current, data->b);
		current = current->next;
	}
}

static t_stack	*find_a_target(t_stack *b_node, t_stack *stack_a)
{
	t_stack	*target;
	t_stack	*current;

	target = NULL;
	current = stack_a;
	while (current)
	{
		if (current->value > b_node->value
			&& (!target || current->value < target->value))
			target = current;
		current = current->next;
	}
	if (!target)
		target = find_smallest_node(stack_a);
	return (target);
}

void	find_a_targets(t_data *data)
{
	t_stack	*current;

	current = data->b;
	while (current)
	{
		current->target = find_a_target(current, data->a);
		current = current->next;
	}
}

void	get_position(t_stack *stack)
{
	t_stack	*current;
	int		pos;

	current = stack;
	pos = 0;
	while (current)
	{
		current->position = pos;
		pos++;
		current = current->next;
	}
}
