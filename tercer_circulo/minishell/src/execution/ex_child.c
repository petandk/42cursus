/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:33:35 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/16 16:21:18 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

char	*find_path_index(t_env *envp)
{
	char	*e;
	t_env	*path_env;

	path_env = find_env_var(envp, "PATH");
	if (!path_env || !path_env->value)
		return (NULL);
	e = ft_strdup(path_env->value);
	if (!malloc_test((void *)e))
		return (NULL);
	return (e);
}

char	*find_path_access(char **all_path, char **cmd)
{
	int		i;
	char	*n_cmd;
	char	*path;

	n_cmd = ft_strjoin("/", cmd[0]);
	if (!n_cmd)
		return (NULL);
	i = 0;
	while (all_path[i])
	{
		path = ft_strjoin(all_path[i++], n_cmd);
		if (!path)
		{
			free(n_cmd);
			return (NULL);
		}
		if (access(path, X_OK) == 0)
			break ;
		free(path);
	}
	free(n_cmd);
	if (all_path[i] == NULL)
		return (NULL);
	return (path);
}

static char	*get_command_path(t_shell *shell, char **cmd)
{
	char	*str;
	char	**all_path;
	char	*path;

	if (cmd && cmd[0] && (cmd[0][0] == '/' || cmd[0][0] == '.'))
		return (cmd[0]);
	str = find_path_index(shell->env);
	if (!str)
		return (return_error_child(cmd[0]));
	all_path = ft_split(str, ':');
	if (access(cmd[0], X_OK) == 0)
		path = cmd[0];
	else
		path = find_path_access(all_path, cmd);
	if (!path)
	{
		free_args(all_path);
		free(str);
		return (return_error_child(cmd[0]));
	}
	free_args(all_path);
	free(str);
	return (path);
}

void	execute_command(char **cmd, t_shell *shell)
{
	char	*path;
	char	**new_env;

	new_env = list_to_matrix(shell->env);
	if (!new_env)
		exit(0);
	if (!cmd || !cmd[0])
		exit(0);
	path = get_command_path(shell, cmd);
	if (!path)
	{
		free_args(new_env);
		return ;
	}
	execve(path, cmd, new_env);
	if (path)
		free(path);
	free_args(new_env);
	ft_putstr_fd(cmd[0], 2);
	ft_putendl_fd(": command not found", 2);
	return ;
}
