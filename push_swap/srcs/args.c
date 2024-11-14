/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:02:13 by rmanzana          #+#    #+#             */
/*   Updated: 2024/11/14 17:27:28 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_args(int argc, char **argv)
{
	int		i;
	int		num;
	t_stack	*nodes_a;

	i = 1;
	nodes_a = NULL;
	check_args(argc, argv);
	if (argc == 3)
		if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
			ft_printf("sa\n");
	if (argc >= 4)
	{
		while (i < argc)
		{
			num = ft_atoi(argv[i]);
			ft_lstadd_backnode(&nodes_a, ft_lstnewnode(num));
			i++;
		}
		if (!is_sorted(nodes_a))
		{
			if (argc == 4)
				order_3(nodes_a);
			else if (argc == 5)
				order_4(nodes_a);
		/*else
			turk(nodes_a);
*/
			
		}
	}
}
