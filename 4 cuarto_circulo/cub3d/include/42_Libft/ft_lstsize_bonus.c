/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:00:42 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/28 13:10:46 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*int	main(void)
{
	int		size;
	t_list	node3;
	t_list	node2;
	t_list	node1;
	t_list	head;

	node3 = {NULL, NULL};
	node2 = {NULL, &node3};
	node1 = {NULL, &node2};
	head = {NULL, &node1};
	size = ft_lstsize(&head);
	printf("Size of the list: %d\n", size);
	return (0);
}*/
