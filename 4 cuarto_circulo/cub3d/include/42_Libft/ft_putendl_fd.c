/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:52:17 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/25 18:04:46 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s != '\0')
		write (fd, s++, 1);
	write (fd, "\n", 1);
}

/*int	main(void)
{
	ft_putendl_fd("Hola Mundo", 1);
	return (0);
}*/
