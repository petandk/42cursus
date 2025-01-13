/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:17:46 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/22 00:02:41 by rmanzana         ###   ########.fr       */
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
			str[str_index++] = copy -> content[node_index++];
			if (copy -> content[node_index - 1] == '\n')
			{
				str[str_index] = '\0';
				return ;
			}
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
	t_list			*new_node;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (!contains_newline(storage))
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read <= 0)
		{
			free(buffer);
			if (chars_read == 0 && storage)
			{
				line = get_line(storage);
				free_list(&storage);
			}
			return (line);
		}
		buffer[chars_read] = '\0';
		new_node = ft_lstnew(buffer);
		if (!new_node)
		{
			free(buffer);
			free_list(&storage);
			return (NULL);
		}
		ft_lstadd_back(&storage, new_node);
	}
	line = get_line(storage);
	keep_last_node(&storage);
	return (line);
}
