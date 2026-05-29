/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:18:25 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 16:00:36 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			index;
	int			sign;
	long long	converted;
	int			max_int;

	index = 0;
	sign = 1;
	converted = 0;
	max_int = 2147483647;
	while ((str[index] == 32) || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-')
		sign = -1;
	if (str[index] == '+' || str[index] == '-')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		converted = converted * 10 + (str[index] - '0');
		if (converted > max_int && sign == 1)
			return (max_int);
		if (converted > max_int && sign == -1)
			return (-(max_int) - 1);
		index++;
	}
	return (converted * sign);
}
/*
#include <stdio.h>

int	main(void)
{
	int	result;
	// Test with valid integers
    printf("Testing with valid integer: %s\n", "123");
    result = ft_atoi("123");
    printf("Result: %d\n", result);

	// Test with valid integers
	printf("Testing with positive integer: %s\n", "+123");
	result = ft_atoi("+123");
	printf("Result: %d\n", result);

    // Test with negative integers
    printf("Testing with negative integer: %s\n", "-123");
    result = ft_atoi("-123");
    printf("Result: %d\n", result);

    // Test with leading zeros
    printf("Testing with integer with leading zeros: %s\n", "0123");
    result = ft_atoi("0123");
    printf("Result: %d\n", result);

    // Test with non-numeric characters
    printf("Testing with non-numeric characters: %s\n", "123abc");
    result = ft_atoi("123abc");
    printf("Result: %d\n", result);

	// Test with sign characters
	printf("Testing with sign characters: %s\n", "----123abc");
	result = ft_atoi("----123abc");
	printf("Result: %d\n", result);

	// Test with non-numeric characters
	printf("Testing with non-numeric characters: %s\n", "+-+-+-+-+-+123abc");
	result = ft_atoi("+-+-+-+-+-+123abc");
	printf("Result: %d\n", result);

	// Test with empty string
    printf("Testing with empty string: %s\n", "");
    result = ft_atoi("");
    printf("Result: %d\n", result);

	// Test with positive overflow
	printf("Testing with positive overflow: %s\n", "5000000000");
	result = ft_atoi("5000000000");
	printf("Result: %d\n", result);

	// Test with negative overflow
	printf("Testing with negative overflow: %s\n", "-5000000000");
	result = ft_atoi("-5000000000");
	printf("Result: %d\n", result);

	// Test with negative overflow
	printf("Testing with negative overflow: %s\n", "-2147483647");
	result = ft_atoi("-2147483647");
	printf("Result: %d\n", result);
    return 0;

}
*/
