/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:36:46 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/16 18:13:32 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	swap_env_content(t_env *a, t_env *b)
{
	char	*temp_name;
	char	*temp_value;

	temp_name = a->name;
	temp_value = a->value;
	a->name = b->name;
	a->value = b->value;
	b->name = temp_name;
	b->value = temp_value;
}

void	sort_env_list(t_env *envlist)
{
	int		swapped;
	t_env	*current;
	t_env	*last;

	last = NULL;
	swapped = 1;
	if (envlist == NULL || envlist->next == NULL)
		return ;
	while (swapped)
	{
		swapped = 0;
		current = envlist;
		while (current->next != last)
		{
			if (ft_strcmp(current->name, current->next->name) > 0)
			{
				swap_env_content(current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
		last = current;
	}
}

int	process_export(char *arg, char ***splitd,
		t_env *env_var, int is_env)
{
	*splitd = split_first(arg, '=');
	if (!*splitd || !*splitd[0])
	{
		if (*splitd)
			free_split(*splitd, -1);
		return (1);
	}
	env_var->name = (*splitd)[0];
	if ((*splitd)[1])
		env_var->value = (*splitd)[1];
	else if (ft_strchr(arg, '='))
		env_var->value = "";
	else
		env_var->value = NULL;
	if (!is_valid_name(env_var->name))
	{
		if (is_env)
			ft_putstr_fd("env: ", 2);
		else
			ft_putstr_fd("export: ", 2);
		ft_putstr_fd(env_var->name, 2);
		ft_putendl_fd(": not a valid identifier", 2);
		return (free_split(*splitd, -1), 1);
	}
	return (0);
}

static int	process_export_args(t_shell *shell, char **args)
{
	char	**splitd;
	t_env	env_var;
	int		ret[2];

	ret[0] = 0;
	ret[1] = 0;
	while (args[ret[0]])
	{
		if (ft_strchr(args[ret[0]], '='))
		{
			env_var.next = NULL;
			if (process_export(args[ret[0]], &splitd, &env_var, 0) == 0)
			{
				update_or_create_var(&shell->env, env_var.name, env_var.value);
				free_split(splitd, -1);
			}
			else
				ret[1] = 1;
		}
		else
			if (handle_no_val_export(shell, args[ret[0]]))
				ret[1] = 1;
		ret[0]++;
	}
	return (ret[1]);
}

int	ft_export(t_shell *shell, char **args)
{
	t_env	*sorted;

	if (!args || !args[0])
	{
		sorted = clone_env_list(shell->env);
		if (!sorted)
			return (1);
		sort_env_list(sorted);
		ft_show_env(sorted, 0);
		clear_env_list(&sorted);
		return (0);
	}
	return (process_export_args(shell, args));
}
