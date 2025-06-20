/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:35:34 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/26 11:54:54 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int main()
{
    char *str = "Hello, World!";
    t_list *node = ft_lstnew((void *)str);

    if (node)
    {
        printf("Content: %s\n", (char *)node->content);
        printf("Next: %p\n", (void *)node->next);
        free(node);
    }
    else
    {
        printf("Error: Memory allocation failed\n");
    }

    return 0;
}*/
