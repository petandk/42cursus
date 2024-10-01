/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:59:37 by rmanzana          #+#    #+#             */
/*   Updated: 2024/10/01 19:55:42 by rmanzana         ###   ########.fr       */
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
static int	count_spaces(const char *input)
{
	int	i;
	int	nums;

	i = 0;
	nums = 1;
	while (input[i] != '\0')
	{
		if (input[i] == ' ')
			nums++;
		i++;
	}
	return (nums);
}

int	*divide_string(const char *input)
{
	int		*number_list;
	char	**split_input;
	int		numbers;
	int		i;
	char	*temp;

	numbers = count_spaces(input);
	number_list = (int *)malloc(numbers * sizeof(int));
	if (number_list == NULL)
		return (NULL);
	split_input = ft_split(input, ' ');
	if (!split_input)
	{
		free(number_list);
		return (NULL);
	}
	i = 0;
	while (split_input[i])
	{
		number_list[i] = ft_atoi(split_input[i]);
		temp = ft_itoa(number_list[i]);
		if (temp == NULL || ft_strncmp(temp, split_input[i], ft_strlen(split_input[i])) != 0)
		{
			free(temp);
			free(number_list);
			free_stack(split_input);
			return (NULL);
		}
		free(temp);
		i++;
	}
	free_stack(split_input);
	return (number_list);
}
