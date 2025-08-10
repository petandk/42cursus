/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:10:07 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/17 16:36:48 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	s;
	unsigned int	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size != 0)
	{
		s = 0;
		while (s < size - 1 && src[s] != '\0')
		{
			dest[s] = src[s];
			s++;
		}
		dest[s] = '\0';
	}
	return (src_len);
}

/*int main(int argc, char **argv)
{
    char dest[256];
    char *src;
    size_t size;

    if(argc != 3)
        return (write (2, "Error", 5));
    src = argv[1];
    size = atoi(argv[2]);
    if(sizeof(dest) < size)
    {
        printf ("El size de dest es menor que size\n");
        return (1);
    }
    ft_strlcpy(dest, src, size);
    printf ("Despues de strlcpy, dest = '%s'\n", dest);
    return (0);
}*/
