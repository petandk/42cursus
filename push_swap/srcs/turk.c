/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:00:26 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/03 15:44:21 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *stack)
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

static int	find_median(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		count;
	int		total;

	current = stack;
	total = ft_countnodes(stack);
	while (current)
	{
		count = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		if (count == total / 2)
			return (current->value);
		current = current->next;
	}
	return (current->value);
}

static void	push_half_b(t_stack **a, t_stack **b, int median, int len)
{
	int		pushed;
	int		i;
	t_stack	*tmp;

	pushed = 0;
	i = 0;
	while (len > 3 && i < len && pushed < len / 2)
	{
		tmp = *a;
		if (tmp->value < median)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (len - pushed > 3)
	{
		pb(a, b);
		pushed++;
	}
}

static void	push_to_b(t_stack **a, t_stack **b)
{
	int		len;
	int		median;

	len = ft_countnodes(*a);
	median = find_median(*a);
	push_half_b(a, b, median, len);
}

void	turk(t_stack *stack)
{
	t_stack	*nodes_a;
	t_stack	*nodes_b;
	t_move	best;

	nodes_a = ft_lstfirstnode(stack);
	nodes_b = NULL;
	push_to_b(&nodes_a, &nodes_b);
	order_3(nodes_a);
	while (nodes_b)
	{
		best = find_best_move(nodes_a, nodes_b);
		execute_rotations(&nodes_a, &nodes_b, best);
		pa(&nodes_a, &nodes_b);
	}
	finish_rotation(&nodes_a, ft_countnodes(nodes_a));
	clean_stacks(&nodes_a, &nodes_b);
}
