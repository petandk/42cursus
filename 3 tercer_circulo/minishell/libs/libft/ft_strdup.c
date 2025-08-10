/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:14:53 by gpolo             #+#    #+#             */
/*   Updated: 2025/02/25 12:19:58 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	dup = (char *)malloc(len);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s, len);
	return (dup);
}
/*
int main()
{
    char original[30] = "Hola, mundo!";
    char *duplicated;

	printf("Ingresa una cadena de origen (máximo 19 caracteres): ");
	if (fgets(original, sizeof(original), stdin) == NULL)
	{
		printf("Error al leer la cadena.\n");
		return 1;
	}
    duplicated = ft_strdup(original);
    if (duplicated == NULL) {
        printf("Error al duplicar la cadena con ft_strdup\n");
        return 1;
    }
    printf("Cadena original: %s\n", original);
    printf("Cadena duplicada: %s\n", duplicated);
    free(duplicated);
    return 0;
}*/
