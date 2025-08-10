/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:19:07 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/02 08:30:29 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int main()
{
	int c;

	c = ft_isascii(128) + '0';
 	write(1,&c, 1);
 	return (0);
}*/
/*int	main(int argc, char **argv)
{
	char	c;
	int		ascii;

	if (argc != 2)
		return (write (2, "Error", 5));
	ascii = atoi(&argv[1][0]);
	c = ft_isascii(ascii) + '0';
	write (1, &c, 1);
	return (0);
}*/
