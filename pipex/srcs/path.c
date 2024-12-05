/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:45:20 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/05 15:50:20 by rmanzana         ###   ########.fr       */
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

char	*get_path(char *command)
{
	char	**possible_paths;
	int		i;
	char	*full_path;

	possible_paths = ft_split(get_system_paths(), ':');
	i = 0;
	while (possible_paths[i])
	{
		full_path = ft_strjoin(possible_paths[i], "/");
		full_path = ft_strjoin(full_path, command);
		if (access(full_path, F_OK) == 0)
		{
			free_array(possible_paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_array(possible_paths);
	return (NULL);
}
