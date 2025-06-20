/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:13:05 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/26 13:48:51 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	if (!lst || !del)
		return ;
	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
/*
void ft_del(void *content)
{
    free(content);
}

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
    t_list *node1, *node2, *node3;

    node1 = ft_lstnew(strdup("First node"));
    node2 = ft_lstnew(strdup("Second node"));
    node3 = ft_lstnew(strdup("Third node"));

    ft_lstadd_back(&head, node1);
    ft_lstadd_back(&head, node2);
    ft_lstadd_back(&head, node3);

    printf("Lista antes de borrar:\n");
    ft_print_list(head);
    printf("\n");

    ft_lstclear(&head, ft_del);

    printf("Lista después de borrar:\n");
    ft_print_list(head);

    return 0;
}*/
