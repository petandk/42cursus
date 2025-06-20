/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:47:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/12 18:20:40 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*add_chr_to_pipe_line(char *line, char c)
{
	char	*temp;
	size_t	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	temp = malloc(len + 2);
	if (!temp)
		return (free(line), NULL);
	ft_strlcpy(temp, line, len + 1);
	temp[len] = c;
	temp[len + 1] = '\0';
	free(line);
	return (temp);
}

char	*read_line_pipe(int fd)
{
	char	c;
	char	*line;
	int		ret;

	line = ft_strdup("");
	if (!line)
		return (NULL);
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret <= 0)
			break ;
		if (c == '\n')
			return (line);
		line = add_chr_to_pipe_line(line, c);
		if (!line)
			return (NULL);
	}
	if (ret < 0 || (ret == 0 && *line == '\0'))
		return (free(line), NULL);
	return (line);
}

t_list	*read_heredoc_pipe(int fd)
{
	char	*line;
	t_list	*lines;
	t_list	*new_node;

	lines = NULL;
	while (1)
	{
		line = read_line_pipe(fd);
		if (!line)
			break ;
		new_node = ft_lstnew(line);
		if (!new_node)
			return (free(line), ft_lstclear(&lines, free), NULL);
		ft_lstadd_back(&lines, new_node);
	}
	return (lines);
}

static int	handle_child(int status, t_shell **shell, int pipe_fd)
{
	int	exit_code;

	if (WIFEXITED(status))
		(*shell)->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		(*shell)->exit_status = 128 + WTERMSIG(status);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		errno = EINTR;
		return (close (pipe_fd), 2);
	}
	else if (WIFEXITED(status))
	{
		exit_code = WEXITSTATUS(status);
		if (exit_code == EXIT_SUCCESS)
			return (0);
		else if (exit_code == 42)
		{
			(*shell)->exit_status = 0;
			return (close(pipe_fd), 42);
		}
		else if ((*shell)->exit_status == 130)
			return (close(pipe_fd), 130);
	}
	return (1);
}

t_list	*parent_process_heredoc(int pipe_fd[2],
		pid_t pid, t_shell **shell)
{
	int		status;
	t_list	*lines;
	int		result;

	close(pipe_fd[1]);
	waitpid(pid, &status, 0);
	result = handle_child(status, shell, pipe_fd[0]);
	if (result == 0)
	{
		lines = read_heredoc_pipe(pipe_fd[0]);
		close(pipe_fd[0]);
		return (lines);
	}
	else
		return (NULL);
}
