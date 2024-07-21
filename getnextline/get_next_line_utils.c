/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:50:03 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/21 20:21:49 by rmanzana         ###   ########.fr       */
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
	t_list	*current;
	t_list	*last;
	t_list	*next;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	current = *lst;
	last = *lst;
	while (last -> next != NULL)
		last = last -> next;
	while (current != last)
	{
		next = current -> next;
		free(current -> content);
		free(current);
		current = next;
	}
	*lst = last;
}

void	free_list(t_list **lst)
{
	if (lst == NULL || *lst == NULL)
		return ;
	keep_last_node(lst);
	free((*lst)-> content);
	free(*lst);
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
