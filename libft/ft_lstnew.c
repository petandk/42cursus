/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:00:30 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/30 19:30:59 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
/*
#include <stdio.h>

int	main(void)
{
	int		num;
	t_list	*node;
	char	*str;

	num = 42;
	node = ft_lstnew(&num);
	if (node)
	{
		printf("Node info:\nContent: %d\nNext: %p\n", *(int *)node -> content, (void *)node -> next);
		free(node);
	}
	else
		printf("Node failed");
	str = "Hello, World!";
	node = ft_lstnew(str);
	if (node)
	{
		printf("Node info:\nContent: %s\nNext: %p\n", (char *)node -> content, (void *)node -> next);
		free(node);
	}
	else
		printf("Node failed");
	return (0);
}
*/
