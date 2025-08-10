/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:22:37 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/16 18:15:19 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*clone_env_list(t_env *envlist)
{
	t_env	*copy;
	t_env	*current;
	t_env	*newnode;

	copy = NULL;
	current = envlist;
	while (current)
	{
		newnode = env_lstnew(current->name, current->value);
		if (!newnode)
		{
			clear_env_list(&copy);
			return (NULL);
		}
		env_lstadd_back(&copy, newnode);
		current = current->next;
	}
	return (copy);
}

void	ft_show_env(t_env *envlist, int is_env)
{
	t_env	*current;

	if (!envlist)
		return ;
	current = envlist;
	while (current)
	{
		if (is_env == 0)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(current->name, 1);
			if (current->value != NULL)
				multend_fd("=\"", current->value, "\"", 1);
			else
				ft_putendl_fd("", 1);
		}
		else if (is_env == 1)
		{
			if (current->value && current->value[0] != '\0')
				multend_fd(current->name, "=", current->value, 1);
		}
		current = current->next;
	}
}

static int	process_env_args(t_shell *shell, char **args, t_env **temp_env)
{
	int		i;
	char	**splitd;
	t_env	env_var;

	*temp_env = clone_env_list(shell->env);
	if (!*temp_env)
		return (1);
	i = 0;
	while (args[i] && ft_strchr(args[i], '='))
	{
		if (process_export(args[i], &splitd, &env_var, 1) == 0)
		{
			update_or_create_var(temp_env, env_var.name, env_var.value);
			free_split(splitd, -1);
		}
		else
			return (clear_env_list(temp_env), 1);
		i++;
	}
	if (args[i])
	{
		ft_putendl_fd("Minishell: Error: Run \"env\" without options.", 2);
		return (clear_env_list(temp_env), 1);
	}
	return (0);
}

void	ft_env(t_shell *shell, char **args)
{
	t_env	*temp_env;

	if (!args || !args[0])
	{
		shell->exit_status = 0;
		return (ft_show_env(shell->env, 1));
	}
	if (process_env_args(shell, args, &temp_env) != 0)
	{
		shell->exit_status = 1;
		return ;
	}
	ft_show_env(temp_env, 1);
	shell->exit_status = 0;
	clear_env_list(&temp_env);
}
