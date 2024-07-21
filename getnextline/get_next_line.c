/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:17:46 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/21 20:22:42 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_to_nl(t_list *lst)
{
	int		i;
	int		len;
	t_list	*copy;

	if (lst == NULL)
		return (0);
	len = 0;
	copy = lst;
	while (copy)
	{
		i = 0;
		while (copy -> content[i])
		{
			if (copy -> content[i] == '\n')
				return (++len);
			i++;
			len++;
		}
		copy = copy -> next;
	}
	return (len);
}

void	create_line(t_list *lst, char *str)
{
	int		node_index;
	int		str_index;
	t_list	*copy;

	if (lst == NULL)
		return ;
	str_index = 0;
	copy = lst;
	while (copy)
	{
		node_index = 0;
		while (copy -> content[node_index])
		{
			if (copy -> content[node_index] == '\n')
			{
				str[str_index++] = '\n';
				str[str_index] = '\0';
				return ;
			}
			str[str_index++] = copy -> content[node_index++];
		}
		copy = copy -> next;
	}
	str[str_index] = '\0';
}

char	*get_line(t_list *lst)
{
	int		str_len;
	char	*str;

	if (lst == NULL)
		return (NULL);
	str_len = len_to_nl(lst);
	str = (char *)malloc((str_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	create_line(lst, str);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list	*storage;
	char			*line;
	char			*buffer;
	int				chars_read;
	int				is_eof;

	line = NULL;
	is_eof = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!contains_newline(storage) && !is_eof)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (chars_read == 0)
		{
			free (buffer);
			is_eof = 1;
		}
		else
		{
			buffer[chars_read] = '\0';
			ft_lstadd_back(&storage, ft_lstnew(buffer));
		}
	}
	line = get_line(storage);
	keep_last_node(&storage);
	if (is_eof && !line)
	{
		free_list(&storage);
		return (NULL);
	}
	return (line);
}
