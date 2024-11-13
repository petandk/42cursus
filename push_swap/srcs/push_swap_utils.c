/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:59:37 by rmanzana          #+#    #+#             */
/*   Updated: 2024/11/13 01:03:14 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack-> next;
		free(temp);
	}
	free(stack);
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
	stack = ft_lstfirstnode(stack);
}
