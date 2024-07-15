/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:17:46 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/15 19:45:27 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}

#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
		printf("Error opening file.");
	else
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("%s\n", line);
			free(line);
		}
	}
	close(fd);
	return (0);
}
