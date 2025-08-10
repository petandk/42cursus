/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:59:38 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/02 08:45:29 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n <= 0)
	{
		n = 1;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	num;
	int		sign;

	num = n;
	sign = 0;
	if (num < 0)
	{
		num = -(long)n;
		sign = 1;
	}
	len = ft_numlen(num) + sign;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

/*int     main(int argc, const char **argv)
{
    char *result;   
    if (argc != 2)
        return (write (2, "Error", 5) );
    result = ft_itoa(atoi(argv[1]));
    printf("%s\n", result);
    free (result);
}*/
/*int	main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(9));
	printf("%s\n", ft_itoa(-9));
	printf("%s\n", ft_itoa(10));
	printf("%s\n", ft_itoa(-15));
	printf("%s\n", ft_itoa(543000));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
}*/
