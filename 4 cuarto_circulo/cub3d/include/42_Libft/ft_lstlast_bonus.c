/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:40:17 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/28 14:49:21 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*int	main(void)
{
	t_list	node3;
	t_list	node2;
	t_list	node1;
	t_list	head;
	t_list	*last;

	node3 = {"Node 3", NULL};
	node2 = {"Node 2", &node3};
	node1 = {"Node 1", &node2};
	head = {"Head", &node1};
	last = ft_lstlast(&head);
	if (last != NULL)
		printf ("Content of the last node: %s\n", (char *)last->content);
	return (0);
}*/
