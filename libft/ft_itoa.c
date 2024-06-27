/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:28:18 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/27 18:00:54 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int number)
{
	int	count;
	int	minint;
	int	num;

	count = 0;
	minint = -2147483648;
	if (number == 0)
		return (1);
	if (number == minint)
		return (10);
	if (number < 0)
		num = -number;
	else
		num = number;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static int	ft_prepare_number(int n, char *str, int *start)
{
	*start = 0;
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (0);
	}
	if (n == -2147483648)
	{
		str[(*start)++] = '-';
		str[(*start)++] = '2';
		return (147483648);
	}
	if (n < 0)
	{
		str[(*start)++] = '-';
		n = -n;
	}
	return (n);
}

static void	ft_fill_string(char *str, int num, int start)
{
	int		i;
	char	aux;

	i = start;
	if (num == 0 && i == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return;
	}
	while (num > 0)
	{
		str[i++] = (num % 10) + '0';
		num /= 10;
	}
	str[i] = '\0';
	i--;
	while (start < i)
	{
		aux = str[start];
		str[start] = str[i];
		str[i] = aux;
		start++;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	int		is_negative;
	int		size;
	int		start;

	digits = ft_count_digits(n);
	is_negative = (n < 0);
	size = digits + is_negative;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	n = ft_prepare_number(n, str, &start);
	ft_fill_string(str, n, start);
	return (str);
}
/*
int	main(void)
{
	int	number;

	//number = -2147483648; // min int
	//number = 2147483647; //  max int
	number = 444;
	printf("%i\nconverted to string:\n%s\n", number, ft_itoa(number));
	return (0);
}
*/
