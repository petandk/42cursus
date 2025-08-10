/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 08:26:07 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/18 18:04:02 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = malloc(num * size);
	if (ptr != NULL)
	{
		ft_memset(ptr, 0, num * size);
	}
	return (ptr);
}

/*int	main(int argc, char *argv[])
{
	size_t	num;
	size_t	size;
	void	*ptr;

	if (argc != 3)
		return (0);
	num = atoi(argv[1]);
	size = atoi(argv[2]);
	ptr = ft_calloc(num, size);
	if (ptr == NULL)
	{
		printf("Error al asignar memoria\n");
		return (1);
	}
	printf("Asignacion de %zu elementos de %zu bytes cada uno\n", num, size);
	free(ptr);
}*/
