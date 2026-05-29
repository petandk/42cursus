/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:05:17 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/01 10:05:27 by rmanzana         ###   ########.fr       */
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
