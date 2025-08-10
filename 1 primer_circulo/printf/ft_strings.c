/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:26:35 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/04 14:56:27 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	index;
	int	result;

	index = 0;
	if (!s)
		s = "(null)";
	while (s[index])
	{
		result = ft_putchar_fd(s[index], fd);
		if (result == -1)
			return (-1);
		index++;
	}
	return (index);
}
