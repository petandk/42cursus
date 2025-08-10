/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:33:38 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/15 16:20:00 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)0;
		i++;
	}
}
/*
int main()
{
    char array[20];
    
	memset(array, 'A', sizeof(array) - 1);
    array[sizeof(array) - 1] = '\0';

    printf("Array antes de ft_bzero: %s\n", array);

    ft_bzero(array, 10);

    printf("Array después de ft_bzero: %s\n", array);

    return 0;
}
*/
