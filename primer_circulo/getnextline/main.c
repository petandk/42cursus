/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:50:36 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/21 23:48:14 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		counter;

	counter = 1;
	fd = open("noline.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file.");
		return (1);
	}
	line = get_next_line(fd);
	while (line) 
	{
		printf("line %d -> %s\n", counter++, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
