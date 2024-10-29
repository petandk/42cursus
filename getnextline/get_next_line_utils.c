/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:50:03 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/22 00:17:42 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (newnode)
	{
		newnode -> content = content;
		newnode -> next = NULL;
		return (newnode);
	}
	return (NULL);
}

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*nodes;

	if (lst == NULL || new_node == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	nodes = *lst;
	while (nodes -> next != NULL)
		nodes = nodes -> next;
	nodes -> next = new_node;
}

void	keep_last_node(t_list **lst)
{
	t_list	*last;
	char	*new_content;
	int		newline_pos;
	int		new_content_pos;
	int		content_len;

	if (!lst || !*lst)
		return ;
	last = *lst;
	while (last -> next)
		last = last -> next;
	newline_pos = 0;
	content_len = 0;
	while (last -> content[content_len])
	{
		if (last -> content[content_len] == '\n' && newline_pos == 0)
			newline_pos = content_len + 1;
		content_len++;
	}
	if (newline_pos == 0)
		newline_pos = content_len;
	new_content = (char *)malloc(content_len - newline_pos + 1);
	if (!new_content)
		return ;
	new_content_pos = 0;
	while (last -> content[newline_pos])
		new_content[new_content_pos++] = last ->content[newline_pos++];
	new_content[new_content_pos] = '\0';
	free_list(lst);
	last = ft_lstnew(new_content);
	if (!last)
	{
		free(new_content);
		*lst = NULL;
		return ;
	}
	*lst = last;
}

void	free_list(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current -> next;
		free(current -> content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

int	contains_newline(t_list *node)
{
	int	i;

	if (node == NULL || node -> content == NULL)
		return (0);
	i = 0;
	while (node -> content[i] != '\0')
	{
		if (node -> content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
