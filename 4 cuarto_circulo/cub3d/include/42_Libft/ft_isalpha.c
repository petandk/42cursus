/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:10:55 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/02 16:32:44 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
{
	int	upper;
	int	lower;

	upper = (c >= 'A' && c <= 'Z');
	lower = (c >= 'a' && c <= 'z');
	if (upper || lower)
		return (1);
	return (0);
}

/*int	main(int argc, char **argv)
{
	char	c;

	if (argc != 2)
		return (write (2, "Error", 5));
	c = ft_isalpha(argv[1][0]) + '0';
	write(1,&c,1);
	return (0);
}*/
