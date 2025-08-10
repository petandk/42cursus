/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:18:09 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/02 08:36:13 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	to_uppercase(unsigned int index, char *c)
{
	(void)index;
	if (*c >= 'a' && *c <= 'z')
		return (*c = *c - ('a' - 'A'));
}

int	main(void)
{
	char	str;

	str[] = "hello world";
	ft_striteri(str, to_uppercase);
	printf("%s\n", str);
	return (0);
}*/
