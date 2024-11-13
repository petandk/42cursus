/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:49:40 by rmanzana          #+#    #+#             */
/*   Updated: 2024/11/13 00:50:42 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lists(t_stack *a,t_stack *b)
{
	t_stack	*curr_a;
	t_stack *curr_b;

	if (a != NULL)
		curr_a = ft_lstfirstnode(a);
	if (b != NULL)
		curr_b = ft_lstfirstnode(b);
	ft_printf(" a  |  b\n");
	ft_printf("---------\n");
	while (curr_a != NULL || curr_b != NULL)
	{
		if (curr_a != NULL)
			ft_printf(" %d ", curr_a-> value);
		else
			ft_printf("     ");
		ft_printf("|  ");
		if (curr_b != NULL)
			ft_printf(" %d ", curr_b -> value);
		ft_printf("\n");

		if (curr_a != NULL)
			curr_a = curr_a -> next;
		if (curr_b != NULL)
			curr_b = curr_b -> next;
	}
}

void	print_single(t_stack *stack)
{
	t_stack *single;

	if (stack != NULL)
		single = ft_lstfirstnode(stack);
	ft_printf(" a \n-----\n");
	while (single != NULL)
	{
		ft_printf(" %d \n", single -> value);
		single = single -> next;
	}
}
