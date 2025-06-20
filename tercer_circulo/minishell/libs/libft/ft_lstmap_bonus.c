/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:18:10 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/28 16:59:41 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	head = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		lst = lst->next;
	}
	return (head);
}
/*
void ft_print_content(void *content)
{
    printf("Content: %s\n", (char *)content);
}

void ft_free_content(void *content)
{
    free(content);
}
void	*ft_strlowcase(char *str)
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
	return (str);
}
int main()
{
    t_list *head = NULL;
    t_list *new_node1;
    t_list *new_node2;
    t_list *new_node3;
    t_list *mapped_list;

    new_node1 = ft_lstnew(strdup("First node"));
    new_node2 = ft_lstnew(strdup("Second node"));
    new_node3 = ft_lstnew(strdup("Third node"));

    ft_lstadd_back(&head, new_node1);
    ft_lstadd_back(&head, new_node2);
    ft_lstadd_back(&head, new_node3);
	ft_lstiter(head, ft_print_content);

    mapped_list = ft_lstmap(head, ft_strlowcase, ft_free_content);

    if (mapped_list)
    {
        printf("Mapped List:\n");
        ft_lstiter(mapped_list, ft_print_content);
        ft_lstclear(&mapped_list, ft_free_content);
    }
    else
    {
        printf("Mapping failed.\n");
    }

    return 0;
}*/
/*cc ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstiter_bonus.c 
ft_lstadd_back_bonus.c
ft_strdup.c ft_lstclear_bonus.c ft_memcpy.c ft_strlen.c ft_lstlast_bonus.c
*/
