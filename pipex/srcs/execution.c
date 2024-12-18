/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:56:34 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/18 21:31:52 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	handle_pipe_error(int pipefd[2])
{
	close(pipefd[0]);
	close(pipefd[1]);
	return (print_error("resource", ""), 2);
}

static int	handle_first_child(t_command *comm, int pipefd[2])
{
	pid_t	pid1;
	int		status1;

	pid1 = fork();
	if (pid1 == -1)
	{
		print_error("no_mem", "");
		return (handle_pipe_error(pipefd));
	}
	if (pid1 == 0)
		exec_first(comm, pipefd);
	waitpid(pid1, &status1, 0);
	if (status1 != 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (12727);
	}
	return (0);
}

static int	handle_second_child(t_command *comm, int pipefd[2])
{
	pid_t	pid2;
	int		status2;

	pid2 = fork();
	if (pid2 == -1)
	{
		print_error("no_mem", "");
		return (handle_pipe_error(pipefd));
	}
	if (pid2 == 0)
		exec_second(comm, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	if (waitpid(pid2, &status2, 0) == -1)
		return (print_error("resource", ""), 2);
	return (status2 != 0);
}

int	exec_comms(t_command	*comm)
{
	int		pipefd[2];
	int		result;

	if (pipe(pipefd) == -1)
		return (print_error("resource", ""), 2);
	result = handle_first_child(comm, pipefd);
	if (result != 0)
		return (result);
	return (handle_second_child(comm, pipefd));
}
