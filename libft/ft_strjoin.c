/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:12:33 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/26 15:44:06 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	l1;
	size_t	l2;
	size_t	index;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	joined = (char *)malloc(l1 + l2 * sizeof(char) + 1);
	if (!joined)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		joined[index] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index])
	{
		joined[l1 + index] = s2[index];
		index++;
	}
	joined[l1 + index] = '\0';
	return (joined);
}
/*
int	main(void)
{
	char *str1 = "Holas que vienen de lejos...";
	char *str2 = "Holas que vienen del mar...";
	char *res = ft_strjoin(str1, str2);
	printf("%s", res);
	free(res);
	return (0);
}
*/
