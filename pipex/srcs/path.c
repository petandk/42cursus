/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:45:20 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/13 20:44:48 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char	**environ;

static char	*get_system_paths(void)
{
	char	**env;

	env = environ;
	while (*env != NULL)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return (*env + 5);
		env++;
	}
	return (NULL);
}

static char	*extract_command(char *full_command)
{
	char	**parts;
	char	*command;

	parts = ft_split(full_command, ' ');
	if (!parts)
		return (NULL);
	command = ft_strdup(parts[0]);
	free_array(parts);
	return (command);
}

static char	*abs_path(char	*command)
{
	if (command[0] == '/' || (command[0] == '.' && command[1] == '/'))
	{
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		free(command);
		return (NULL);
	}
	return (command);
}

static char	*search_path(char	*command)
{
	char	**possible_paths;
	char	*full_path;
	char	*temp_path;
	int		i;

	if (command[0] == '.' && command[1] == '/')
		return (command);
	possible_paths = ft_split(get_system_paths(), ':');
	if (!possible_paths)
		return (free(command), NULL);
	i = 0;
	while (possible_paths[i])
	{
		temp_path = ft_strjoin(possible_paths[i], "/");
		full_path = ft_strjoin(temp_path, command);
		free(temp_path);
		if (access(full_path, F_OK | X_OK) == 0)
			return (free(command), free_array(possible_paths), full_path);
		free(full_path);
		i++;
	}
	free(command);
	free_array(possible_paths);
	return (NULL);
}

char	*get_path(char *full_command)
{
	char	*command;
	char	*path;

	command = extract_command(full_command);
	if (!command)
		return (NULL);
	path = abs_path(command);
	if (path == command)
		return (search_path(command));
	return (path);
}
