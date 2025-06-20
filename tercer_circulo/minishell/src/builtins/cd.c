/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:49:34 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/16 18:05:47 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*go_back(void)
{
	char	*current;
	char	*last_slash;

	current = getcwd(NULL, 0);
	if (current == NULL)
		return (NULL);
	if (ft_strncmp(current, "/", 2) == 0)
		return (current);
	last_slash = ft_strrchr(current, '/');
	if (last_slash)
	{
		*last_slash = '\0';
		if (*current == '\0')
		{
			free(current);
			return (ft_strdup("/"));
		}
	}
	return (current);
}

static char	*new_path(t_shell *shell, char *dest)
{
	char	*newpath;
	char	*oldpwd;

	if ((!dest || ft_strncmp(dest, "", 1) == 0)
		|| (ft_strncmp(dest, "~", 1) == 0))
		newpath = go_home(shell);
	else if (ft_strncmp(dest, "..", 2) == 0)
		newpath = go_back();
	else if (ft_strncmp(dest, "-", 1) == 0)
	{
		oldpwd = get_oldpwd(shell);
		if (!oldpwd)
			return (ft_putendl_fd("cd: OLDPWD not set", 2), NULL);
		newpath = ft_strdup(oldpwd);
		if (newpath)
			ft_putendl_fd(newpath, 1);
	}
	else
		newpath = ft_strdup(dest);
	return (newpath);
}

static void	update_pwd_env(t_env *env)
{
	char	*current;
	t_env	*pwd_node;

	current = getcwd(NULL, 0);
	if (!current)
		return ;
	pwd_node = find_env_var(env, "PWD");
	if (pwd_node)
	{
		free(pwd_node->value);
		pwd_node->value = current;
	}
	else
		free (current);
}

static int	change_directory(t_shell *shell, char *dest, char *newpath)
{
	char	*current;

	current = getcwd(NULL, 0);
	if (!current)
	{
		shell->exit_status = 1;
		ft_putendl_fd("minishell: cd: getcwd error", 2);
		free(newpath);
		return (1);
	}
	if (chdir(newpath) == -1)
	{
		shell->exit_status = 1;
		printerror("no_file", dest);
		free(newpath);
		free(current);
		return (1);
	}
	update_oldpwd_env(shell, current);
	update_pwd_env(shell->env);
	free(newpath);
	free(current);
	shell->exit_status = 0;
	return (0);
}

void	ft_cd(t_shell *shell, char *dest)
{
	char	*newpath;

	newpath = new_path(shell, dest);
	if (!newpath)
	{
		shell->exit_status = 1;
		return ;
	}
	change_directory(shell, dest, newpath);
}
