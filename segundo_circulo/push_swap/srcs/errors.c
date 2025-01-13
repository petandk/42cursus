/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:25:35 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/08 20:42:32 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_onlydigits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1] == '\0')
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	only_numbers(int args, char **argv)
{
	int	i;

	i = 1;
	while (i < args)
	{
		if (!(str_onlydigits(argv[i])))
			return (0);
		i++;
	}
	return (1);
}

static int	check_numbers_size(int args, char **argv)
{
	int	i;
	int	len;

	i = 1;
	while (i < args)
	{
		len = ft_strlen(argv[i]);
		if (argv[i][0] == '-')
		{
			if (len > 11)
				return (0);
			if (len == 11 && ft_strncmp(argv[i], "-2147483648", 11) > 0)
				return (0);
		}
		else
		{
			if (len > 10)
				return (0);
			if (len == 10 && ft_strncmp(argv[i], "2147483647", 10) > 0)
				return (0);
		}
		i++;
	}
	return (1);
}

static int	check_no_repeat(int args, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < args)
	{
		j = i + 1;
		while (j < args)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_args(int args, char **argv)
{
	int	result;

	result = 1;
	if (!only_numbers(args, argv))
		result = 0;
	else if (!check_numbers_size(args, argv))
		result = 0;
	else if (!check_no_repeat(args, argv))
		result = 0;
	if (!result)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
