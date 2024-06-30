/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:36:29 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/30 19:48:55 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new -> next = *lst;
		*lst = new;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*list = ft_lstnew("Old");
	ft_lstadd_front(&list, ft_lstnew("New"));
	t_list	*node = list;
	while (node)
	{
		printf("%s\n", (char *)node -> content);
		node = node -> next;
	}
	return (0);
}
*/
