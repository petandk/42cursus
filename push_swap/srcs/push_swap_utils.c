/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:59:37 by rmanzana          #+#    #+#             */
/*   Updated: 2024/10/18 13:57:03 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(char **stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		free(stack[i]);
		i++;
	}
	free(stack);
}

int	*get_numbers(char *argv[], int argc)
{
	int		*number_list;
	int		i;
	char	*temp;

	number_list = (int *) malloc((argc - 1) * sizeof(int));
	if (number_list == NULL)
		return NULL;
	i = 1;
	while(i < argc)
	{
		number_list[i - 1] = ft_atoi(argv[i]);
		temp = ft_itoa(number_list[i-1]);
		if (temp == NULL || ft_strncmp(temp, argv[i], ft_strlen(argv[i])) != 0)
		{
			free(temp);
			free(number_list);
			return (NULL);
			ft_printf("Error\n");
		}
		free(temp);
		i++;
	}
	return (number_list);
}

int	check_repeated(int *numbers, int argc)
{
	int	j;
	int	i;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
