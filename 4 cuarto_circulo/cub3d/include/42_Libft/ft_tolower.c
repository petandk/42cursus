/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:06:32 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/17 18:09:38 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

/*int	main(int argc, char **argv)
{
	char	result;

	if (argc != 2)
		return (write (2, "Error", 5));
	result = ft_tolower(argv[1][0]);
	printf ("La minuscula de %c, es %c.", argv[1][0], result);
	return (0);
}*/
