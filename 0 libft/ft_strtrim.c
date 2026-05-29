/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:45:06 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/01 14:58:45 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_appears(char c, char *str)
{
	int	found;
	int	index;

	found = 0;
	index = 0;
	if (str == NULL)
		return (0);
	while (str[index] && !found)
	{
		if (str[index] == c)
			found = 1;
		index++;
	}
	return (found);
}

static char	*ft_cleanstring(int start, int end, char *from, char *to)
{
	int	index;

	index = 0;
	while (start <= end)
	{
		to[index] = from[start];
		index++;
		start++;
	}
	to[index] = '\0';
	return (to);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*finalstring;
	int		start;
	int		end;
	char	*str;
	char	*subs;

	start = 0;
	end = ft_strlen(s1) - 1;
	str = (char *)s1;
	subs = (char *)set;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_appears(str[start], subs))
		start++;
	while (end > start && ft_appears(str[end], subs))
		end--;
	finalstring = (char *)malloc(end - start + 2 * sizeof(char));
	if (!finalstring)
		return (NULL);
	return (ft_cleanstring(start, end, str, finalstring));
}
/*
#include <stdio.h>

int	main(void)
{
	char *str = "123ho1a543";
	char *trm = "1234567890";
	char *result = ft_strtrim(str,trm);
	printf("Original: %s\nResultado:%s", str, result);
	free (result);
	return (0);
}
*/
