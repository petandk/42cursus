/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:10:34 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/26 11:25:49 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		c;
	t_list	*current;

	current = lst;
	c = 0;
	while (current)
	{
		current = current->next;
		c++;
	}
	return (c);
}
/*
int main()
{
    t_list *head = NULL;
    t_list *new_node1;
    t_list *new_node2;
    t_list *new_node3;

    new_node1 = ft_lstnew("First node");
    new_node2 = ft_lstnew("Second node");
    new_node3 = ft_lstnew("Third node");

	ft_lstadd_front(&head, new_node3);
    ft_lstadd_front(&head, new_node2);
    ft_lstadd_front(&head, new_node1);    

	printf("List size: %d\n", ft_lstsize(head));

    free(new_node1);
    free(new_node2);
    free(new_node3);

    return 0;
}*/
