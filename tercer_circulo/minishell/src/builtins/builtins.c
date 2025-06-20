/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:24:14 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/16 18:16:26 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	builtins_split(t_shell *shell, char **cmd)
{
	if (!ft_strcmp(cmd[0], "pwd"))
		return (ft_pwd(shell), 1);
	else if (!ft_strcmp(cmd[0], "export"))
	{
		if (cmd[1])
			return (ft_export(shell, cmd + 1), 1);
		else
			return (ft_export(shell, NULL), 1);
	}
	else if (!ft_strcmp(cmd[0], "unset"))
		return (ft_unset(&(shell)->env, cmd + 1), 1);
	else if (!ft_strcmp(cmd[0], "env"))
	{
		if (cmd[1] == NULL)
			return (ft_env(shell, NULL), 1);
		else
			return (ft_env(shell, cmd + 1), 1);
	}
	return (0);
}

int	builtins(t_shell *shell, char **cmd)
{
	if (!ft_strcmp(cmd[0], "exit"))
	{
		if (cmd[1] && cmd[1][0] != '\0')
		{
			if (!is_valid_number(cmd[1]))
			{
				ft_putendl_fd("exit", 2);
				printerror("no_exit", cmd[1]);
				return (ft_exit_no_print(&shell, 2), 1);
			}
			return (ft_exit(&shell, ft_atoi(cmd[1])), 1);
		}
		else
			return (ft_exit(&shell, shell->exit_status), 1);
	}
	if (!ft_strcmp(cmd[0], "echo"))
		return (ft_echo(shell, cmd), 1);
	else if (!ft_strcmp(cmd[0], "cd"))
	{
		if (cmd[2])
			return (ft_putendl_fd("Minishell: cd: too many arguments", 2), 1);
		return (ft_cd(shell, cmd[1]), 1);
	}
	return (builtins_split(shell, cmd));
}
