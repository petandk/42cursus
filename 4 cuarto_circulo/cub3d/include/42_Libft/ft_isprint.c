/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:44:06 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/02 08:31:30 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*int	main(int argc, char **argv)
{
	char	c;
	int		print;

	if (argc != 2)
		return (write (2, "Error", 5));
	print = atoi(&argv[1][0]);
	c = ft_isprint(print) + '0';
	write(1, &c, 1);
	return (0);
}*/
