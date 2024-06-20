/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:47:20 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/20 18:05:03 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*cpy;

	i = 0;
	while (s[i])
		i++;
	cpy = (char *)malloc(i * sizeof(char) + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
/*
int	main(void)
{
	char *str = "lorem ipsum dolor sit amet";
	char *cpy = ft_strdup(str);
	printf("%s", cpy);
	return (0);
}
*/
