/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:59:59 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/06 18:25:25 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	len_expan(char *str, int start)
{
	char	c;
	int		len;

	len = 0;
	if (str[start] == '?')
		return (1);
	while (str[start + len])
	{
		c = str[start + len];
		if (ft_isalnum(c) || c == '_')
			len++;
		else
			break ;
	}
	return (len);
}

static char	*find_value(char *key, t_env *env, int exst)
{
	t_env	*var;
	char	*value;

	if (!malloc_test((void *)key))
		exit(1);
	if (ft_strcmp(key, "?") == 0)
	{
		value = ft_itoa(exst);
		free(key);
		return (value);
	}
	var = find_env_var(env, key);
	free(key);
	if (var)
		value = var->value;
	else
		value = "";
	return (value);
}

char	*ft_strjoin_doblefree(char *s1, char *s2)
{
	char	*join;

	join = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (join);
}

static int	process_dollar(char *str, t_shell **shell, t_expan *ex, char **tmp)
{
	int		len;
	char	*value;
	char	*key;

	len = len_expan(str, ex->i + 1);
	if (len == 0)
	{
		(*tmp) = ft_strdup("$");
		ex->new_str = ft_strjoin_doblefree(ex->new_str, (*tmp));
		ex->i++;
		return (1);
	}
	key = ft_substr(str, ex->i + 1, len);
	value = find_value(key, (*shell)->env, (*shell)->exit_status);
	(*tmp) = ft_strdup(value);
	ex->new_str = ft_strjoin_doblefree(ex->new_str, (*tmp));
	ex->i += len + 1;
	return (0);
}

char	*heredoc_expansion(char *str, t_shell **shell)
{
	t_expan	ex;
	char	*tmp;

	ex.i = 0;
	ex.new_str = ft_strdup("");
	while (str && str[ex.i])
	{
		if (str[ex.i] == '$')
		{
			if (process_dollar(str, shell, &ex, &tmp) == 1)
				continue ;
		}
		else
		{
			tmp = ft_substr(str, ex.i, 1);
			ex.new_str = ft_strjoin_doblefree(ex.new_str, tmp);
			ex.i++;
		}
	}
	return (ex.new_str);
}
