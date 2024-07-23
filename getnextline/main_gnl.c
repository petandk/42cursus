/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:09:24 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/23 16:02:09 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	*line;
	int		fd;

	if (argc == 1 || argv[1][0] == '\0')
	{
		printf("Debes introducir el archivo a leer.");
		return (1);	
	}
	i = 1;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	printf("Linea %d -> %s\n", i, line);
	free(line);
	while(line)
	{
		i++;
		line = get_next_line(fd);
		printf("Linea %d -> %s\n", i, line);
		free(line);
	}
	close(fd);
	return (0);
}
