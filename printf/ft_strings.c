/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:26:35 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/03 19:38:04 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if(!s)
		s = "(null)";
	while (s[index])
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
	return (index);
}
