/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:50:03 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/15 18:50:49 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*buff;
	size_t			i;

	buff = (unsigned char *)malloc(sizeof (char) * (size * nmemb));
	if (!buff)
		return (NULL);
	i = 0;
	if (nmemb > 0)
	{
		while (i < nmemb * size)
			buff[i++] = 0;
	}
	return (buff);
}
