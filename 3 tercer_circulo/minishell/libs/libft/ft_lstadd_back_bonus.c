/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:34:45 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/28 16:50:43 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/*
void ft_print_list(t_list *lst)
{
    t_list *current = lst;
    while (current)
    {
        printf("Content: %s\n", (char *)current->content);
        current = current->next;
    }
}
int main()
{
    t_list *head = NULL;
    t_list *new_node1;
    t_list *new_node2;
    t_list *new_node3;

    new_node1 = ft_lstnew("First node");
    new_node2 = ft_lstnew("Second node");
    new_node3 = ft_lstnew("Third node");

    ft_lstadd_back(&head, new_node1);
    ft_lstadd_back(&head, new_node2);
    ft_lstadd_back(&head, new_node3);

    ft_print_list(head);

    free(new_node1);
    free(new_node2);
    free(new_node3);

    return 0;
}*/
