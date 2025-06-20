/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:47:19 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/19 15:00:33 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*array;
	size_t	total_size;

	total_size = num * size;
	array = malloc(total_size);
	if (array == NULL)
		return (NULL);
	ft_memset(array, 0, total_size);
	return (array);
}
/*
int main() 
{
    int *array;
    size_t num_elements = 10;
    size_t element_size = sizeof(int);

    array = (int *)ft_calloc(num_elements, element_size);
    if (array == NULL) 
	{
        printf("Error al asignar memoria con ft_calloc\n");
        return 1;
    }

    printf("Valores iniciales del array asignado con ft_calloc:\n");
    for (size_t i = 0; i < num_elements; i++)
	{
        printf("array[%zu] = %d\n", i, array[i]);
    }

    free(array);

    return 0;
}*/
