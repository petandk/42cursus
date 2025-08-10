/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmult_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:18:55 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/10 19:12:57 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	multend_fd(char *s1, char *s2, char *s3, int fd)
{
	if (s1 && s2 && s3 && fd)
	{
		ft_putstr_fd(s1, fd);
		ft_putstr_fd(s2, fd);
		ft_putendl_fd(s3, fd);
	}
}

void	mult_fd(char *s1, char *s2, char *s3, int fd)
{
	if (s1 && s2 && s3 && fd)
	{
		ft_putstr_fd(s1, fd);
		ft_putstr_fd(s2, fd);
		ft_putstr_fd(s3, fd);
	}
}
