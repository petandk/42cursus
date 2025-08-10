/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:24:58 by rmanzana          #+#    #+#             */
/*   Updated: 2025/07/31 20:01:45 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

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
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = ft_remainder(buffer);
	return (line);
}
