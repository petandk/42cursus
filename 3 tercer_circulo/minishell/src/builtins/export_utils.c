/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:32:41 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/16 18:17:28 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_lstnew(char *name, char *val)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (0);
	new_node->name = ft_strdup(name);
	if (!new_node->name)
		return (free(new_node), NULL);
	if (val)
	{
		new_node->value = ft_strdup(val);
		if (!new_node->value)
			return (free(new_node->name), free(new_node), NULL);
	}
	else
		new_node->value = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_env	*env_lstlast(t_env *env)
{
	if (env == NULL)
		return (0);
	while (env->next != NULL)
		env = env->next;
	return (env);
}

void	env_lstadd_back(t_env **env, t_env *newenv)
{
	t_env	*last;

	if (!env || !newenv)
		return ;
	if (*env == NULL)
		*env = newenv;
	else
	{
		last = env_lstlast(*env);
		last->next = newenv;
	}
}

char	**free_split(char **result, size_t i)
{
	size_t	j;

	if (!result)
		return (NULL);
	if (i == (size_t) - 1)
	{
		j = 0;
		while (result[j])
			free(result[j++]);
	}
	else
		while (i > 0)
			free(result[--i]);
	free(result);
	return (NULL);
}

t_env	*create_env_list(char **envp)
{
	t_env	*envlist;
	char	**split_res;
	t_env	*new_node;

	if (!envp || !*envp)
		return (create_basic_env());
	envlist = NULL;
	while (*envp)
	{
		split_res = split_first(*envp, '=');
		if (!split_res)
			return (clear_env_list(&envlist), NULL);
		if (!split_res[0])
			return (free(split_res), clear_env_list(&envlist), NULL);
		new_node = env_lstnew(split_res[0], split_res[1]);
		if (!new_node)
			return (free_split(split_res, -1), clear_env_list(&envlist), NULL);
		env_lstadd_back(&envlist, new_node);
		free_split(split_res, -1);
		envp++;
	}
	return (envlist);
}
