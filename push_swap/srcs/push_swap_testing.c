/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_testing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:23:20 by rmanzana          #+#    #+#             */
/*   Updated: 2024/10/01 19:16:55 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //para printf
#include "push_swap.h"

void print_results(t_stack *nodes_a, t_stack *nodes_b)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = ft_lstfirst(nodes_a);
	current_b = ft_lstfirst(nodes_b);
	printf("\n-_-_-_-_-_-\n\n");
	while(current_a !=NULL || current_b != NULL)
	{
		if(current_a != NULL)
		{
			printf("a: %-3d | ", current_a -> value);
			current_a = current_a -> next;
		}
		else
			printf("a: --- | ");
		if(current_b != NULL)
		{
			printf("b: %d\n", current_b -> value);
			current_b = current_b -> next;	
		}
		else
			printf("b: ---\n");
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*nodes_a;
	t_stack	*nodes_b;
	int		num;
	t_stack	*current_a;
	t_stack	*current_b;

	nodes_a = NULL;
	nodes_b = NULL;
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			num = atoi(argv[i]);
			ft_lstadd_back(&nodes_a, ft_lstnew(num));
			i++;
		}
		print_results(nodes_a, nodes_b);
		ft_swap(&nodes_a);
		print_results(nodes_a, nodes_b);
		ft_rotate(&nodes_a);
		print_results(nodes_a, nodes_b);
		ft_reverse(&nodes_a);
		print_results(nodes_a, nodes_b);
		ft_push(&nodes_a, &nodes_b);
		ft_push(&nodes_a, &nodes_b);
		ft_push(&nodes_a, &nodes_b);
		ft_push(&nodes_a, &nodes_b);
		ft_push(&nodes_a, &nodes_b);
		print_results(nodes_a, nodes_b);
		ft_push(&nodes_b, &nodes_a);
		ft_push(&nodes_b, &nodes_a);
		print_results(nodes_a, nodes_b);
		ft_swap(&nodes_b);
		print_results(nodes_a, nodes_b);
		ft_rotate(&nodes_b);
		print_results(nodes_a, nodes_b);
		ft_reverse(&nodes_b);
		print_results(nodes_a, nodes_b);
		ft_swap_both(&nodes_a, &nodes_b);
		print_results(nodes_a, nodes_b);
		ft_rotate_both(&nodes_a, &nodes_b);
		print_results(nodes_a, nodes_b);
		ft_reverse_both(&nodes_a, &nodes_b);
		print_results(nodes_a, nodes_b);
		while (nodes_a != NULL)
		{
			current_a = nodes_a;
			nodes_a = nodes_a -> next;
			free (current_a);
		}
		while (nodes_b != NULL)
		{
			current_b = nodes_b;
			nodes_b = nodes_b-> next;
			free(current_b);
		}
	}
	return (0);
}
