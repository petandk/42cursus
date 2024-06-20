/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:28:26 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/15 15:54:16 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int	main(void)
{
	char str[] = "hola que tal";
	char *str_ptr = str;
	ft_bzero(str_ptr, 4);
	printf("%s\n",str);
	return (0);
}
*/
