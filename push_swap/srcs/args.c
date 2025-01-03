/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:02:13 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/03 15:45:26 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_stacks(t_stack **a, t_stack **b)
{
	if (a && *a)
		free_stack(*a);
	if (b && *b)
		free_stack(*b);
}

static void	process_args_help(int argc, t_stack *nodes_a)
{
	if (argc == 4)
		order_3(nodes_a);
	else if (argc == 5)
		order_4(nodes_a);
	else
		turk(nodes_a);
}

void	process_args(int argc, char **argv)
{
	int		i;
	int		num;
	t_stack	*nodes_a;
	t_stack *newnode;

	i = 1;
	nodes_a = NULL;
	newnode = NULL;
	check_args(argc, argv);
	if (argc == 3)
	{
		if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
			ft_printf("sa\n");
		return ;
	}
	if (argc >= 4)
	{
		while (i < argc)
		{
			num = ft_atoi(argv[i]);
			newnode = ft_lstnewnode(num);
			if (!newnode)
			{
				free_stack(nodes_a);
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
			ft_lstadd_backnode(&nodes_a, newnode);
			i++;
		}
		if (!is_sorted(nodes_a))
			process_args_help(argc, nodes_a);
	}
}
