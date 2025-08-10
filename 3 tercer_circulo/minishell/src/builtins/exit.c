/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:56:33 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/15 14:54:13 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit_no_print(t_shell **shell, int exit_code)
{
	if (!shell || !*shell)
		exit(exit_code & 0xFF);
	cleanup_shell(shell);
	exit (exit_code & 0xFF);
}

void	ft_exit_no_full_init(t_shell **shell, int exit_code)
{
	if (!shell || !*shell)
		exit(exit_code & 0xFF);
	if ((*shell)->env)
		clear_env_list(&(*shell)->env);
	free(*shell);
	*shell = NULL;
	ft_putendl_fd("exit", 1);
	exit(exit_code & 0xFF);
}

void	ft_exit(t_shell **shell, int exit_code)
{
	ft_putendl_fd("exit", 1);
	(*shell)->exit_status = exit_code;
	ft_exit_no_print(shell, exit_code);
}
