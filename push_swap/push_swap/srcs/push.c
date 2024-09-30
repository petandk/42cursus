/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:15:17 by rmanzana          #+#    #+#             */
/*   Updated: 2024/09/30 20:50:18 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **src, t_list **dest)
{
	t_list	*src_head;
	t_list	*dest_head;
	t_list	*new_head;

	src_head = *src;
	dest_head = *dest;
	if (src_head == NULL)
		return ;
	new_head = src_head -> next;
	new_head -> prev = NULL;
	src_head -> next = dest_head;
	*src = new_head;
	*dest = src_head;
}
