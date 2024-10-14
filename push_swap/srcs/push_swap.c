/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:57:45 by rmanzana          #+#    #+#             */
/*   Updated: 2024/10/14 20:31:13 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*numbers;
	int	i;

	numbers = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		numbers = divide_string(argv[1]);
		i = 0;
		while (i < (argc - 1))
		{
			ft_printf("%d", numbers[i]);
			i++;
		}
	}
	if (argc > 2)
	{
		numbers = get_numbers(argv, argc);
		i = 0;
		while (i < (argc - 1))
		{
			ft_printf("%d", numbers[i]);
			i++;
		}
	}
	if (check_repeated(numbers, argc - 1))
		ft_printf("\nrepeated nums");
	else
		ft_printf("\nnon repeated");
	free(numbers);
	return (0);
}
