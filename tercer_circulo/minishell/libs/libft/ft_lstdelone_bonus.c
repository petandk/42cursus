/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:58:22 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/26 13:47:55 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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
void free_content(void *content)
{
    free(content);
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

    printf("Borrando el segundo nodo (node2):\n");
    ft_lstdelone(node2, free_content);
    node2 = NULL;

    printf("Lista después de borrar:\n");
    ft_print_list(head);

    printf("\nLiberando memoria de la lista completa:\n");
    while (head)
    {
        t_list *tmp = head->next;
        ft_lstdelone(head, free_content);
        head = tmp;
    }

    return 0;
}*/
