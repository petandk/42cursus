/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:27:55 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/03 15:12:32 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_a_rot(t_stack **a, int pos_a)
{
	int	len_a;
	int	i;

	len_a = ft_countnodes(*a);
	if (pos_a <= len_a / 2)
	{
		i = pos_a;
		while (i--)
			ra(a);
	}
	else
	{
		i = len_a - pos_a;
		while (i--)
			rra(a);
	}
}

static void	execute_b_rot(t_stack **b, int pos_b)
{
	int	len_b;
	int	i;

	len_b = ft_countnodes(*b);
	if (pos_b <= len_b / 2)
	{
		i = pos_b;
		while (i--)
			rb(b);
	}
	else
	{
		i = len_b - pos_b;
		while (i--)
			rrb(b);
	}
}

void	execute_rotations(t_stack **a, t_stack **b, t_move move)
{
	execute_a_rot(a, move.pos_a);
	execute_b_rot(b, move.pos_b);
}

void	finish_rotation(t_stack **a, int len)
{
	int	smallest_pos;
	int	i;

	smallest_pos = find_smallest(*a);
	if (smallest_pos <= len / 2)
	{
		i = smallest_pos;
		while (i--)
			ra(a);
	}
	else
	{
		i = len - smallest_pos;
		while (i--)
			rra(a);
	}
}
