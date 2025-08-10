/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:07:54 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/06 19:28:29 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_3(t_stack *stack)
{
	t_stack	*biggest;

	biggest = find_biggest(stack);
	if (biggest == stack)
		ra(&stack);
	else if (biggest == stack -> next)
		rra(&stack);
	if (stack -> value > stack -> next -> value)
		sa(&stack);
}

static int	find_min_pos(t_stack *stack)
{
	t_stack	*current;
	int		min;
	int		pos;
	int		min_pos;

	current = stack;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

void	order_4(t_stack *stack)
{
	t_stack	*stack_b;
	int		pos;
	int		size;

	stack_b = NULL;
	pos = find_min_pos(stack);
	size = ft_countnodes(stack);
	while (pos > 0 && pos <= size / 2)
	{
		ra(&stack);
		pos--;
	}
	while (pos > size / 2 && pos < size)
	{
		rra(&stack);
		pos++;
	}
	pb(&stack, &stack_b);
	order_3(stack);
	pa(&stack, &stack_b);
}
