/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:22:39 by rmanzana          #+#    #+#             */
/*   Updated: 2024/09/25 20:31:53 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *lst)
{
	t_list	*tmp;
	int		aux;

	if (!lst)
		return ;
	tmp = lst -> next;
	if (!tmp)
		return ;
	aux = lst -> value;
	lst -> value = tmp -> value;
	tmp -> value = aux;
}

void	ft_swap_both(t_list *a, t_list *b)
{
	ft_swap(a);
	ft_swap(b);
}
