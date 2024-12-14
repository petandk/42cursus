/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:26:35 by rmanzana          #+#    #+#             */
/*   Updated: 2024/10/01 19:29:31 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_singlechar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstring_fd(char *s, int fd)
{
	int	index;
	int	result;

	index = 0;
	if (!s)
		s = "(null)";
	while (s[index])
	{
		result = ft_singlechar_fd(s[index], fd);
		if (result == -1)
			return (-1);
		index++;
	}
	return (index);
}
