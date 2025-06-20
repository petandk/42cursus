/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:57:49 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/15 15:58:22 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process(t_fork_data *data, t_comand_data *cmd, t_shell *shell)
{
	child_execution_signals();
	if_pid_0(data, cmd);
	if (handle_redirections(&cmd[data->i]) == -1)
	{
		cleanup_shell(&shell);
		exit(126);
	}
	if (cmd[data->i].comand && cmd[data->i].comand[0])
	{
		if ((!builtins(shell, cmd[data->i].comand)))
			execute_command(cmd[data->i].comand, shell);
		cleanup_shell(&shell);
		exit(127);
	}
	exit(0);
}

void	parent_process(t_fork_data *data)
{
	else_pid_0(&data->prev_fd, data->pipefd, data->i, data->cmd_count);
}

void	start_fork(t_fork_data *data, t_comand_data *cmd, t_shell *shell,
		pid_t *pids)
{
	if (data->i < data->cmd_count - 1)
		handle_pipe(data->pipefd);
	handle_fork(&data->pid);
	pids[data->i] = data->pid;
	if (data->pid == 0)
		child_process(data, cmd, shell);
	else
		parent_process(data);
	data->i++;
}

void	set_exit_status(t_shell *shell, int status)
{
	if (WIFEXITED(status))
		shell->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		shell->exit_status = 128 + WTERMSIG(status);
}

void	wait_children(pid_t *pids, int cmd_count, t_shell *shell)
{
	int	i;
	int	status;

	i = 0;
	while (i < cmd_count)
	{
		waitpid(pids[i], &status, 0);
		if (i == cmd_count - 1)
			set_exit_status(shell, status);
		i++;
	}
}
