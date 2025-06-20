/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:12:32 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/15 16:35:13 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		exit(1);
}

void	handle_fork(pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
		exit(1);
}

void	if_pid_0(t_fork_data *data, t_comand_data *cmd)
{
	int	has_output_redir;

	child_execution_signals();
	if (data->prev_fd != -1)
	{
		dup2(data->prev_fd, STDIN_FILENO);
		close(data->prev_fd);
	}
	has_output_redir = cmd[data->i].out_file && cmd[data->i].out_count > 0;
	if (!has_output_redir && data->i < data->cmd_count - 1)
		dup2(data->pipefd[1], STDOUT_FILENO);
	if (data->i < data->cmd_count - 1)
	{
		close(data->pipefd[1]);
		close(data->pipefd[0]);
	}
}

void	else_pid_0(int *prev_fd, int *pipefd, int i, int cmd_count)
{
	if (*prev_fd != -1)
		close(*prev_fd);
	if (i < cmd_count - 1)
		close(pipefd[1]);
	*prev_fd = pipefd[0];
}

void	execute_pipeline(t_comand_data *cmd, int cmd_count, t_shell *shell)
{
	t_fork_data	data;
	pid_t		*pids;

	execution_signals();
	data.i = 0;
	data.prev_fd = -1;
	data.cmd_count = cmd_count;
	while (data.i < cmd_count)
		expancion_var(&cmd[data.i++], shell);
	data.i = 0;
	if (check_single_builtin(cmd, cmd_count, shell))
		return ;
	pids = ft_calloc(cmd_count + 1, sizeof(pid_t));
	if (!pids)
		return ;
	shell->pids = pids;
	if (init_all_heredocs(cmd, cmd_count, &shell) == -1)
		return (free_heredoc_fail(pids, shell), (void)0);
	while (data.i < cmd_count)
		start_fork(&data, cmd, shell, pids);
	wait_children(pids, cmd_count, shell);
	cleanup_heredocs(cmd, cmd_count);
	free(pids);
	shell->pids = NULL;
	shell_signals();
}
