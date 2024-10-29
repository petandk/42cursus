/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_patri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:07:02 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/23 17:07:57 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("prueba.txt", O_RDONLY);
	if (fd == -1)
		return (printf("Error al abrir el archivo"), 1);
	line = get_next_line(fd);
	printf("[%d]:%s", count, line);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
		printf("[%d]:%s", count, line);
	}
	close(fd);
	return (0);
}
