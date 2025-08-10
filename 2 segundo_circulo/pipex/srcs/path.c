/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:27:11 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/18 20:26:06 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char	**environ;

static char	*get_system_paths(void)
{
	char	**env;
	char	*paths;

	if (!environ)
		return (NULL);
	env = environ;
	while (*env != NULL)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			paths = *env + 5;
			if (!paths)
				return (NULL);
			return (paths);
		}
		env++;
	}
	return (NULL);
}

char	*get_path(char *command)
{
	char	**possible_paths;
	int		i;
	char	*full_path;

	if (command[0] == '/')
	{
		if (access(command, F_OK) == 0)
			return (ft_strdup(command));
		return (NULL);
	}
	possible_paths = ft_split(get_system_paths(), ':');
	i = 0;
	while (possible_paths[i])
	{
		full_path = ft_strjoin(possible_paths[i], "/");
		full_path = ft_strjoin(full_path, command);
		if (access(full_path, F_OK) == 0)
			return (free_array(possible_paths), full_path);
		free(full_path);
		i++;
	}
	free_array(possible_paths);
	return (NULL);
}
