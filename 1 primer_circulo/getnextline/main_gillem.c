/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gillem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:39:24 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/24 13:59:33 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*line;
	char	tmp;
	int		read_bytes = 1;
	int		count = 0, i = 0;

	fd = open("prueba2.txt", O_RDONLY);
	if (fd == -1)
		return (printf("Error al abrir el archivo"), 1);
	while (read_bytes == 1)
	{
		read_bytes = read(fd, &tmp, 1);
		{
			if (tmp == '\n' && read_bytes == 1)
				count++;
		}
	}
	close(fd);
	printf("%i\n", count);
	fd = open("prueba2.txt", O_RDONLY);
	if (fd == -1)
		return (printf("Error al abrir el archivo"), 1);

	while (i < count)
	{
		i++;
		line = get_next_line(fd);
		printf("[%d]:%s", count, line);
		free(line);
	}
	close(fd);
	return (0);
}
