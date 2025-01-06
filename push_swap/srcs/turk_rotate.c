/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:10:02 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/06 23:41:19 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_r_both(t_data *data, t_stack *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		rr(&data->a, &data->b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	while (cheapest->cost_a < 0 && cheapest->cost_b > 0)
	{
		rrr(&data->a, &data->b);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
}

void	turk_r_a(t_data *data, t_stack *cheapest)
{
	if (cheapest == NULL)
		return ;
	while (cheapest->cost_a > 0)
	{
		ra(&data->a);
		cheapest->cost_a--;
	}
	while (cheapest->cost_a < 0)
	{
		rra(&data->a);
		cheapest->cost_a++;
	}
}

void	turk_r_b(t_data *data, t_stack *cheapest)
{
	if (cheapest == NULL)
		return ;
	while (cheapest->cost_b > 0)
	{
		rb(&data->b);
		cheapest->cost_b--;
	}
	while (cheapest->cost_b < 0)
	{
		rrb(&data->b);
		cheapest->cost_b++;
	}
}

void	turk_to_b(t_data *data, t_stack *cheapest)
{
	turk_r_both(data, cheapest);
	turk_r_a(data, cheapest);
	turk_r_b(data, cheapest);
	pb(&data->a, &data->b);
}

void	turk_to_a(t_data *data)
{
	t_stack	*cheapest;

	while (data->b)
	{
		find_a_targets(data);
		get_position(data->a);
		get_position(data->b);
		get_cost_returning(data);
		cheapest = find_cheapest(data);
		turk_r_both(data, cheapest);
		turk_r_a(data, cheapest);
		turk_r_b(data, cheapest);
		pa(&data->a, &data->b);
	}
}
