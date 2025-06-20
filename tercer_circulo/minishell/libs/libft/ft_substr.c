/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:41:28 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/30 13:37:00 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	c;
	size_t	s_len;

	c = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (s[start + c] && c < len)
	{
		substr[c] = s[start + c];
		c++;
	}
	substr[c] = '\0';
	return (substr);
}
/*
int main(void)
{
	char	s[] = "Gyan Polo LLorens";
	char	*substring;
	int		start;
	size_t	len;
	
	printf("Cadena original: ");
	printf("%s\n",s);
	printf("Introduzca un caracter int para el start; ");
	scanf("%d",&start);
	printf("Introduzca un caracter size_t para el len; ");
	scanf("%zu",&len);
 	substring = ft_substr(s, start, len);
	if (substring == NULL)
	{
        printf("Error al obtener la subcadena\n");
        return 1;
    }
	printf("Substring : %s\n",substring);
	free(substring);
	return 0;
}*/
