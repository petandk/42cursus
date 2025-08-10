/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline_utils1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:58:37 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/15 17:30:54 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_single_builtin(t_comand_data *cmd, int cmd_count, t_shell *shell)
{
	if (cmd_count == 1 && cmd[0].comand && cmd[0].comand[0])
	{
		if ((!cmd[0].in_file || cmd[0].in_count == 0) && (!cmd[0].out_file
				|| cmd[0].out_count == 0))
		{
			if (builtins(shell, cmd[0].comand))
			{
				shell_signals();
				return (1);
			}
		}
	}
	return (0);
}

void	free_heredoc_fail(pid_t *pids, t_shell *shell)
{
	free(pids);
	shell->pids = NULL;
	shell_signals();
}

char	*return_error_child(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": command not found", 2);
	return (NULL);
}
