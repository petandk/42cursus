/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:17:13 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/03 15:36:21 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_target_pos(t_stack *a, int num)
{
	t_stack	*current;
	int		target_pos;
	int		current_pos;
	int		found;

	current = a;
	target_pos = 0;
	current_pos = 0;
	found = 0;
	while (current && current->next)
	{
		if (current->value < num && current->next->value > num)
		{
			target_pos = current_pos +1;
			found = 1;
			break ;
		}
		current = current->next;
		current_pos++;
	}
	if (!found)
		target_pos = find_smallest(a);
	return (target_pos);
}

static int	calculate_cost(int pos_a, int pos_b, int len_a, int len_b)
{
	int	cost;

	cost = 0;
	if (pos_a <= len_a / 2)
		cost += pos_a;
	else
		cost += len_a - pos_a;
	if (pos_b <= len_b / 2)
		cost += pos_b;
	else
		cost += len_b - pos_b;
	return (cost);
}

t_move	find_best_move(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_move	best;
	int		pos_b;
	int		t_pos;
	int		cost;

	current_b = b;
	pos_b = 0;
	best.cost = 2147483647;
	while (current_b)
	{
		t_pos = find_target_pos(a, current_b->value);
		cost = calculate_cost(t_pos, pos_b, ft_countnodes(a), ft_countnodes(b));
		if (cost < best.cost)
		{
			best.cost = cost;
			best.pos_a = t_pos;
			best.pos_b = pos_b;
		}
		current_b = current_b->next;
		pos_b++;
	}
	return (best);
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
	clean_stacks(&nodes_a, &nodes_b);
}
