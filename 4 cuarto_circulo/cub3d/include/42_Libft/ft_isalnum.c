/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 09:55:29 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/02 08:29:55 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	int	upper;
	int	lower;
	int	number;

	upper = (c >= 'A' && c <= 'Z');
	lower = (c >= 'a' && c <= 'z');
	number = (c >= '0' && c <= '9');
	if (number || lower || upper)
		return (1);
	return (0);
}

/*int	main(int argc, char **argv)
{
	char	c;

	if (argc != 2)
		return (write (2, "Error", 5));
	c = ft_isalnum(argv[1][0]) + '0';
	write (1, &c, 1);
	return (0);
}*/
