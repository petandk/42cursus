/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:56:32 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/26 11:54:08 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
int main()
{
    t_list *head = NULL;
    t_list *new_node1;
    t_list *new_node2;

    new_node1 = ft_lstnew("First node");
    new_node2 = ft_lstnew("New first node");

    ft_lstadd_front(&head, new_node1);
    ft_lstadd_front(&head, new_node2);

    t_list *current = head;
    while (current)
    {
        printf("Content: %s\n", (char *)current->content);
        current = current->next;
    }

    return 0;
}*/
