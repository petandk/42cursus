/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:14:22 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/10 19:05:53 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_env_node(t_env *node)
{
	if (!node)
		return ;
	free(node->name);
	free(node->value);
	free(node);
}

static int	remove_env_var(t_env **envlist, char *name)
{
	t_env	*current;
	t_env	*prev;

	current = *envlist;
	prev = NULL;
	if (current && ft_strcmp(current->name, name) == 0)
	{
		*envlist = current->next;
		free_env_node(current);
		return (0);
	}
	while (current && ft_strcmp(current->name, name) != 0)
	{
		prev = current;
		current = current->next;
	}
	if (current)
	{
		prev->next = current->next;
		free_env_node(current);
	}
	return (0);
}

static void	unset_helper(t_env **envlist, char *name, int *error)
{
	int	ret;

	if (!is_valid_name(name))
	{
		printerror("no_unset", name);
		(*error)++;
	}
	else
	{
		ret = remove_env_var(envlist, name);
		if (ret != 0)
			(*error)++;
	}
}

int	ft_unset(t_env **envlist, char **names)
{
	int	i;
	int	error_cnt;

	if (!envlist || !*envlist || !names)
		return (1);
	error_cnt = 0;
	i = 0;
	while (names[i])
	{
		unset_helper(envlist, names[i], &error_cnt);
		i++;
	}
	if (error_cnt > 0)
		return (1);
	return (0);
}
