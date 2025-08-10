/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:23:33 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/02 08:31:01 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	int	number;

	number = (c >= '0' && c <= '9');
	if (number)
		return (1);
	return (0);
}

/*int	main(int argc, char **argv)
{
	int	c;

	if (argc != 2)
		return (write (2, "Error", 5));
	c = ft_isdigit(argv[1][0]) + '0';
	write(1, &c, 1);
	return (0);
}*/
