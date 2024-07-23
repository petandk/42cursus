/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:24:58 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/23 17:10:10 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*remainder(char *buffer)
{
	int		i;
	int		j;
	char	*rem;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	while (buffer[j])
		j++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	rem = (char *)malloc(((j - i) + 1) * sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		rem[j++] = buffer[i++];
	free(buffer);
	return (rem);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = remainder(buffer);
	return (line);
}
