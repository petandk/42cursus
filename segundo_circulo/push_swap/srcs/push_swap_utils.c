/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:59:37 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/07 19:23:08 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack && stack->prev)
		stack = stack->prev;
	while (stack != NULL)
	{
		temp = stack;
		stack = stack-> next;
		if (temp->prev)
			temp->prev->next = NULL;
		if (temp->next)
			temp->next->prev = NULL;
		temp->next = NULL;
		temp->prev = NULL;
		temp->target = NULL;
		free(temp);
	}
}

t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*biggest;

	if (stack == NULL)
		return (NULL);
	biggest = stack;
	while (stack != NULL)
	{
		if (stack -> value > biggest -> value)
			biggest = stack;
		stack = stack -> next;
	}
	return (biggest);
}

int	find_smallest(t_stack *stack)
{
	int	smallest;

	if (stack == NULL)
		return (0);
	smallest = stack->value;
	while (stack != NULL)
	{
		if (stack->value < smallest)
			smallest = stack->value;
		stack = stack->next;
	}
	return (smallest);
}

int	is_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack -> next != NULL)
	{
		if (stack -> value > stack -> next -> value)
			return (0);
		stack = stack -> next;
	}
	return (1);
}
