/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:51:30 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/15 17:41:18 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printerror(char *err_type, char *name)
{
	if (ft_strncmp(err_type, "no_file", 7) == 0)
		multend_fd("minishell: ", name, ": No such file or directory", 2);
	if (ft_strncmp(err_type, "no_unset", 8) == 0)
		multend_fd("unset: ", name, ": not a valid identifier", 2);
	if (ft_strncmp(err_type, "no_exit", 7) == 0)
		multend_fd("Minishell: exit: ", name, ": numeric argument required", 2);
	if (ft_strncmp(err_type, "no_perm", 7) == 0)
		multend_fd("minishell: ", name, ": Permission denied", 2);
}

void	control_d_error(char *delimiter)
{
	ft_putstr_fd("minishell: warning: here-document ", 2);
	ft_putstr_fd("delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putendl_fd("')", 2);
}
