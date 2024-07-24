/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:24:58 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/24 15:05:45 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_remainder(char *buffer)
{
	int		i;
	int		j;
	char	*rem;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	j = i;
	while (buffer[j])
		j++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	rem = (char *)malloc(((j - i) + 1) * sizeof(char));
	if (!rem)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		rem[j++] = buffer[i++];
	rem[j] = '\0';
	free(buffer);
	return (rem);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc((i + 1 + (buffer[i] == '\n')) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	buffer[fd] = ft_remainder(buffer[fd]);
	return (line);
}
