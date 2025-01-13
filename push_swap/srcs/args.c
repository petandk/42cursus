/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:02:13 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/08 20:29:03 by rmanzana         ###   ########.fr       */
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

static t_stack	*create_node(int num, t_stack *nodes_a)
{
	t_stack	*newnode;

	newnode = ft_lstnewnode(num);
	if (!newnode)
	{
		free_stack(nodes_a);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (newnode);
}

static t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*nodes_a;
	t_stack	*newnode;
	int		i;

	nodes_a = NULL;
	i = 1;
	while (i < argc)
	{
		newnode = create_node(ft_atoi(argv[i]), nodes_a);
		if (newnode == NULL)
			return (NULL);
		ft_lstadd_backnode(&nodes_a, newnode);
		i++;
	}
	return (nodes_a);
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
	t_stack	*nodes_a;

	nodes_a = NULL;
	check_args(argc, argv);
	if (argc == 3)
	{
		if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
			ft_printf("sa\n");
		return ;
	}
	if (argc >= 4)
	{
		nodes_a = init_stack(argc, argv);
		if (!is_sorted(nodes_a))
			process_args_help(argc, nodes_a);
		clean_stacks(&nodes_a, NULL);
	}
}
