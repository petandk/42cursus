/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:04:02 by rmanzana          #+#    #+#             */
/*   Updated: 2024/10/29 19:18:48 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		num;
	t_stack	*nodes_a;

	i = 1;
	nodes_a = NULL;
	if (argc == 2)
		return (0);
	if (argc == 3)
		if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
			ft_printf("sa\n");
	if (argc == 4)
	{
		while (i < argc)
		{
			num = ft_atoi(argv[i]);
			ft_lstadd_backnode(&nodes_a, ft_lstnewnode(num));
			i++;
		}
		order_3(nodes_a);
	}
	return (0);
}
