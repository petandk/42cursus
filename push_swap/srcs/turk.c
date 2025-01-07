/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:00:26 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/07 22:49:43 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_data *data)
{
	t_stack	*current;
	int		size_a;
	int		size_b;

	size_a = ft_countnodes(data->a);
	size_b = ft_countnodes(data->b);
	current = data->a;
	while (current)
	{
		if (current->target)
		{
			current->cost_a = current->position;
			if (current->position > get_mid(size_a))
				current->cost_a = -(size_a - current->position);
			if (current->target->position > get_mid(size_b))
				current->cost_b = -(size_b - current->target->position);
			else
				current->cost_b = current->target->position;
		}
		current = current->next;
	}
}

int	total_cost(t_stack *node)
{
	int	cost;

	cost = 0;
	if (node-> cost_a < 0)
		cost = -node->cost_a;
	else
		cost = node->cost_a;
	if (node->cost_b < 0)
		cost += -node->cost_b;
	else
		cost += node->cost_b;
	return (cost);
}

t_stack	*find_cheapest(t_data	*data)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		best;
	int		cost;

	current = data->a;
	cheapest = current;
	best = 2147483647;
	while (current)
	{
		cost = total_cost(current);
		if (cost == 0)
			return (current);
		if (cost < best)
		{
			best = cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

static void	move_2(t_data *data)
{
	pb(&data->a, &data->b);
	pb(&data->a, &data->b);
	if (data->b->value < data->b->next->value)
		sb(&data->b);
}

void print_stack(t_stack *stack, char *name)
{
	t_stack	*head;

	head = ft_lstfirstnode(stack);
    ft_printf("%s stack: ", name);
    while (head)
    {
        ft_printf("%d ", head->value);
        head = head->next;
    }
    ft_printf("\n");
}

void	turk(t_stack *stack)
{
	t_data	data;
	t_stack	*cheapest;

	data.a = stack;
	data.b = NULL;
	move_2(&data);
	while (ft_countnodes(data.a) > 3)
	{
		find_b_targets(&data);
		get_position(data.a);
		get_position(data.b);
		get_cost(&data);
		cheapest = find_cheapest(&data);
		turk_to_b(&data, cheapest);
	//	print_stack(data.a, "a");
	//	print_stack(data.b, "b");
	}
	//print_stack(data.a, "a bef");
	order_3(data.a);
	//print_stack(data.a, "a");
	//print_stack(data.b, "b");
	turk_to_a(&data);
	//print_stack(data.a, "turka");
	//print_stack(data.b, "turkb");
	if (!is_sorted(data.a))
		final_sort(&data.a);
	print_stack(data.a, "A");
}
