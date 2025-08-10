/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isalpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:09:07 by pamanzan          #+#    #+#             */
/*   Updated: 2024/09/30 11:38:24 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_isalpha(char *str)
{
	int	upper;
	int	lower;

	while (*str != '\0')
	{
		upper = (*str >= 'A' && *str <= 'Z');
		lower = (*str >= 'a' && *str <= 'z');
		if (!upper && !lower)
			return (0);
		str++;
	}
	return (1);
}
