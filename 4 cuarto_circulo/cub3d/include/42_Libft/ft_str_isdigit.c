/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:38:42 by pamanzan          #+#    #+#             */
/*   Updated: 2024/09/30 11:54:29 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_isdigit(char *str)
{
	int	number;

	if (str[0] == '-')
		str++;
	while (*str != '\0')
	{
		number = (*str >= '0' && *str <= '9');
		if (!number)
			return (0);
		str++;
	}
	return (1);
}
