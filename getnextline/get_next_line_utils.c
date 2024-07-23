/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:50:00 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/23 16:58:05 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_helper(int i, int j, char *str1, char *str2)
{
	int		k;
	char	*ret;

	k = 0;
	ret = (char *)malloc(((i + j) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (k < i)
	{
		ret[k] = str1[k];
		k++;
	}
	while (k < i + j)
	{
		ret[k] = str2[k - i];
		k++;
	}
	ret[k] = '\0';
	return (ret);
}

static char	*ft_join(char *gnl, char *buf)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!buf)
		return (NULL);
	while (gnl[i])
		i++;
	while (buf[j])
		j++;
	result = join_helper(i, j, gnl, buf);
	free(gnl);
	return (result);
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
	line = (char *)malloc((i + 2) * sizeof(char));
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

static int	contains_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_file(int fd, char *buffer)
{
	char	*aux;
	int		bytes_read;

	if (!buffer)
	{
		buffer = (char *)malloc(1 * sizeof(char));
		buffer[0] = '\0';
	}
	aux = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, aux, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(aux), NULL);
		aux[bytes_read] = '\0';
		buffer = ft_join(buffer, aux);
		if (contains_newline(buffer))
			break ;
	}
	free(aux);
	return (buffer);
}
