/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:57:45 by rmanzana          #+#    #+#             */
/*   Updated: 2024/10/01 19:59:01 by rmanzana         ###   ########.fr       */
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
		while (numbers[i] != '\0')
		{
			ft_printf("%d", numbers[i]);
			i++;
		}
	}
	return (0);
}
