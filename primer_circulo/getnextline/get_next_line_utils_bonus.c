/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:50:00 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/24 14:49:24 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*join_helper(int i, int j, char *str1, char *str2)
{
	int		k;
	char	*ret;

	k = 0;
	ret = (char *)malloc(((i + j) + 1) * sizeof(char));
	if (!ret || !str1 || !str2)
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
	if (!buf || !gnl)
		return (NULL);
	while (gnl[i])
		i++;
	while (buf[j])
		j++;
	result = join_helper(i, j, gnl, buf);
	if (!result)
		return (NULL);
	free(gnl);
	return (result);
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

static char	*init_buffer(void)
{
	char	*buffer;

	buffer = (char *)malloc(1 * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	return (buffer);
}

char	*read_file(int fd, char *buffer)
{
	char	*aux;
	int		bytes_read;

	if (!buffer)
		buffer = init_buffer();
	if (!buffer)
		return (NULL);
	aux = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, aux, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(aux), free(buffer), NULL);
		aux[bytes_read] = '\0';
		buffer = ft_join(buffer, aux);
		if (!buffer)
			return (free(aux), NULL);
		if (contains_newline(buffer))
			break ;
	}
	free(aux);
	return (buffer);
}
