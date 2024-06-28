/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:11:59 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 15:56:55 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*spt1;
	unsigned char	*spt2;
	size_t			index;

	spt1 = (unsigned char *)s1;
	spt2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (spt1[index] != spt2[index])
			return (spt1[index] - spt2[index]);
		index++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	//char	*s1 = "lorem asilu";
	//char	*s2 = "lorem dolor";
	char	*s1 = "zyxbcdefgh";
	char	*s2 = "abcdefgxz";
	if (ft_memcmp(s1,s2,0) < 0)
		printf("s1 4 the win\n");
	if (ft_memcmp(s1,s2,0) == 0)
		printf("are equal\n");
	if (ft_memcmp(s1,s2,0) > 0)
		printf("s2 winz\n");
	printf("%d", ft_memcmp(s1,s2,0));
	

	return(0);
}
*/
