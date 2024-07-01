/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:06:37 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/01 10:06:45 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*nodes;
	int		counter;

	nodes = lst;
	counter = 0;
	while (nodes)
	{
		nodes = nodes -> next;
		counter++;
	}
	return (counter);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list *list = ft_lstnew("3");

	ft_lstadd_front(&list, ft_lstnew("2"));
	ft_lstadd_front(&list, ft_lstnew("1"));
	printf("Nodes: %d\n", ft_lstsize(list));
	return (0);
}
*/
