/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:23:20 by rmanzana          #+#    #+#             */
/*   Updated: 2024/09/25 20:33:34 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //para printf
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_list	*nodes;
	int		num;
	t_list	*current;

	nodes = NULL;
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			num = atoi(argv[i]);
			ft_lstadd_back(&nodes, ft_lstnew(num, i - 1));
			i++;
		}
		current = nodes;
		while (current != NULL)
		{
			printf("Numero: %d,Indice: %d\n", current -> value, current -> index);
			current = current -> next;
		}
		ft_swap(nodes);
		current = nodes;
		while (current != NULL)
		{
			printf("Numero: %d,Indice: %d\n", current -> value, current -> index);
			current = current -> next;
		}
		while (nodes != NULL)
		{
			current = nodes;
			nodes = nodes -> next;
			free (current);
		}
	}
	return (0);
}
