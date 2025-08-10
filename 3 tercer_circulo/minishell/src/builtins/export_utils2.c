/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:23:05 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/16 17:42:17 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_or_create_var(t_env **envlist, char *name, char *value)
{
	t_env	*exist;

	exist = find_env_var(*envlist, name);
	if (exist)
	{
		if (value != NULL)
		{
			free(exist->value);
			exist->value = ft_strdup(value);
			if (!exist->value)
				return (1);
		}
	}
	else
	{
		exist = env_lstnew(name, value);
		if (!exist)
			return (1);
		env_lstadd_back(envlist, exist);
	}
	return (0);
}

t_env	*create_basic_env(void)
{
	t_env	*envlist;
	t_env	*newnode;
	char	*pwd;

	envlist = NULL;
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		newnode = env_lstnew("PWD", pwd);
		if (newnode)
			env_lstadd_back(&envlist, newnode);
		free(pwd);
	}
	newnode = env_lstnew("SHLVL", "1");
	if (newnode)
		env_lstadd_back(&envlist, newnode);
	newnode = env_lstnew("PATH", "/usr/local/bin:/usr/bin:/bin");
	if (newnode)
		env_lstadd_back(&envlist, newnode);
	return (envlist);
}

t_env	*find_env_var(t_env *envlist, char *name)
{
	t_env	*current;

	if (!envlist || !name)
		return (NULL);
	current = envlist;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

int	count_env_nodes(t_env *envlist)
{
	int		count;
	t_env	*current;

	count = 0;
	if (!envlist)
		return (0);
	current = envlist;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	clear_env_list(t_env **envlist)
{
	t_env	*aux;

	if (!envlist || !*envlist)
		return ;
	while (*envlist)
	{
		aux = (*envlist)->next;
		if ((*envlist)->name)
		{
			free((*envlist)->name);
			(*envlist)->name = NULL;
		}
		if ((*envlist)->value)
		{
			free((*envlist)->value);
			(*envlist)->value = NULL;
		}
		free(*envlist);
		*envlist = aux;
	}
}
