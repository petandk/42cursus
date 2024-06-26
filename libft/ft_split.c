/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:33:59 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/26 19:31:08 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordscounter(char *s, char c)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while(s[index])
	{
		if (s[index] == c)
			count++;
		index++;
	}
	return(count + 1);
}

void ft_freemalloc(char **s, int cnt)
{
	int	i;
	
	i = 0;
	while (i < cnt)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char *str;
	str = (char *)s;
	returnarray = (char **)malloc(ft_wordscounter(str, c) * sizeof(char *));
	if (!returnarray)
		return (NULL);
}
