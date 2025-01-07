/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_fixes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:39:25 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/07 22:42:53 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_cheapest_back(t_data	*data)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		best;
	int		cost;

	current = data->b;
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
