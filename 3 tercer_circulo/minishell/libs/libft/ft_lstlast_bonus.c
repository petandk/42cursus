/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:00:08 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/26 12:31:34 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int main()
{
    t_list *head = NULL;
    t_list *new_node1;
    t_list *new_node2;
    t_list *new_node3;
    t_list *last_node;

    new_node1 = ft_lstnew("First node");
    new_node2 = ft_lstnew("Second node");
    new_node3 = ft_lstnew("Third node");

    ft_lstadd_front(&head, new_node3);
    ft_lstadd_front(&head, new_node2);
    ft_lstadd_front(&head, new_node1);

    last_node = ft_lstlast(head);
    if (last_node)
        printf("Last node content: %s\n", (char *)last_node->content);
    else
        printf("The list is empty.\n");

    free(new_node1);
    free(new_node2);
    free(new_node3);

    return 0;
}*/
