/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:24:09 by gpolo             #+#    #+#             */
/*   Updated: 2024/12/19 13:17:12 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		leng;
	int		c;
	int		c2;

	c = 0;
	c2 = 0;
	if (!s1 && !s2)
		return (0);
	leng = (ft_strlen(s1) + ft_strlen(s2));
	join = (char *)malloc(sizeof(char) * (leng + 1));
	if (!join)
		return (0);
	while (s1 && s1[c])
	{
		join[c] = s1[c];
		c++;
	}
	while (s2 && s2[c2])
		join[c++] = s2[c2++];
	join[c] = '\0';
	return (join);
}
/*
int main()
{
	char s1[20];
	char s2[20];
	char *join;

	printf("Ingresa una cadena 's1' (máximo 19 caracteres): ");
	if (fgets(s1, sizeof(s1), stdin) == NULL)
	{
		printf("Error al leer la cadena.\n");
		return 1;
	}
	printf("Ingresa una cadena 's2' (máximo 19 caracteres): ");
	if (fgets(s2, sizeof(s2), stdin) == NULL)
	{
		printf("Error al leer la cadena.\n");
		return 1;
	}
	s1[strcspn(s1, "\n")] = '\0';
	s2[strcspn(s2, "\n")] = '\0';
	join = ft_strjoin(s1, s2);
	if (join == NULL)
	{
        printf("Error al unir las cadenas\n");
        return 1;
    }
	printf("Resultado ft_strjoin : %s\n",join);
	free(join);
	return (0);
}*/
