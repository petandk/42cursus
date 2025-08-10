/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:42:10 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/15 20:55:48 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_oldpwd_env(t_shell *shell, char *old_path)
{
	t_env	*oldpwd_node;

	if (!old_path)
		return ;
	oldpwd_node = find_env_var(shell->env, "OLDPWD");
	if (oldpwd_node)
	{
		free(oldpwd_node->value);
		oldpwd_node->value = ft_strdup(old_path);
	}
	else
		update_or_create_var(&shell->env, "OLDPWD", old_path);
}

char	*get_oldpwd(t_shell *shell)
{
	t_env	*oldpwd;

	oldpwd = find_env_var(shell->env, "OLDPWD");
	if (!oldpwd || !oldpwd->value)
		return (NULL);
	return (oldpwd->value);
}

char	*go_home(t_shell *shell)
{
	t_env	*home;

	home = find_env_var(shell->env, "HOME");
	if (!home || !home->value)
	{
		ft_putendl_fd("minishell: cd: HOME not set", 2);
		return (NULL);
	}
	return (ft_strdup(home->value));
}
