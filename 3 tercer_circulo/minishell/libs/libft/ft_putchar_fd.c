/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:38:02 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/22 15:44:49 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main()
{
    ft_putchar_fd('A', 1);
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error abriendo el archivo");
        return 1;
    }
    ft_putchar_fd('B', fd);
    if (close(fd) == -1)
    {
        perror("Error cerrando el archivo");
        return 1;
    }

    return 0;
}*/
