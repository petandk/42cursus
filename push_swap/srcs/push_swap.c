/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:23:20 by rmanzana          #+#    #+#             */
/*   Updated: 2024/09/30 20:50:44 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //para printf
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_list	*nodes_a;
	t_list	*nodes_b;
	int		num;
	t_list	*current_a;
	t_list	*current_b;

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
		current_a = ft_lstfirst(nodes_a);
		current_b = ft_lstfirst(nodes_b);
		while (current_a != NULL)
		{
			printf("a: %d\n", current_a -> value);
			current_a = current_a -> next;
		}
		ft_swap(&nodes_a);
		printf("-_-_-_-_-_-\n");
		current_a = ft_lstfirst(nodes_a);
		while (current_a != NULL)
		{
			printf("a: %d\n", current_a -> value);
			current_a = current_a -> next;
		}	
		ft_rotate(&nodes_a);
		current_a = ft_lstfirst(nodes_a);
		printf("-_-_-_-_-_-\n");
		while (current_a != NULL)
		{
			printf("a: %d\n", current_a -> value);
			current_a = current_a -> next;
		}
		ft_reverse(&nodes_a);
		current_a = ft_lstfirst(nodes_a);
		printf("-_-_-_-_-_-\n");
		while (current_a != NULL)
		{
			printf("a: %d\n", current_a -> value);
			current_a = current_a -> next;
		}
		ft_push(&nodes_a, &nodes_b);
		current_a = ft_lstfirst(nodes_a);
		current_b = ft_lstfirst(nodes_b);
		printf("-_-_-_-_-_-\n");
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
