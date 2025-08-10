/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:51:42 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/26 14:17:38 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	while (current)
	{
		f(current->content);
		current = current->next;
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
void free_content(void *content)
{
    free(content);
}
void	ft_strlowcase(char *str)
{
	int	cuenta;

	cuenta = 0;
	while (str[cuenta] != '\0')
	{
		if (str[cuenta] >= 'a' && str[cuenta] <= 'z')
		{
			str[cuenta] = str[cuenta] - 32;
		}
		cuenta++;
	}
	return ;
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

    printf("Lista antes de aplicar ft_lstiter:\n");
    ft_print_list(head);
    printf("\n");

    printf("Aplicando ft_lstiter para imprimir cada nodo:\n");
    ft_lstiter(head, ft_strlowcase);
    printf("\n");
	ft_print_list(head);

    printf("Liberando memoria de la lista completa:\n");
    while (head)
    {
        t_list *tmp = head->next;
        free(head->content);
        free(head);
        head = tmp;
    }

    return 0;
}*/
