/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:22:44 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/11 18:03:34 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	len_expan(char *str, int start, t_quotes quote)
{
	int		len;
	char	c;

	len = 0;
	if (str[start] == '?')
		return (1);
	if (quote.quote_start == quote.quote_end && start > quote.quote_end
		&& quote.quote != 0)
		return (0);
	while (str[start + len])
	{
		c = str[start + len];
		if (start + len == quote.quote_start && start + len == quote.quote_end)
			break ;
		if (start + len == quote.quote_start || start + len == quote.quote_end)
		{
			if (start + len == quote.quote_end && (ft_isalnum(c) || c == '_'))
				len++;
			break ;
		}
		if (!ft_isalnum(c) && c != '_')
			break ;
		len++;
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
		value = ft_strdup(var->value);
	else
		value = ft_strdup("");
	return (value);
}

static void	process_dollar(t_expan *ex, char **str,
	t_quotes *quote, t_shell *shell)
{
	int		len;
	char	*value;
	char	*tmp;

	index_value(quote, ex);
	len = len_expan(*str, ex->start, quote[ex->j]);
	if (len == 0 && (quote[ex->j].quote == 0
			|| (!(quote[ex->j].quote_start > quote[ex->j].quote_end)
				&& quote[ex->j].quote != 0
				&& quote[ex->j].quote_start != ex->start)))
	{
		tmp = ft_substr(*str, ex->i, 1);
		ex->new_str = ft_strjoin_free(ex->new_str, tmp);
		free(tmp);
		ex->i++;
		return ;
	}
	value = find_value(ft_substr(*str, ex->start, len),
			shell->env, shell->exit_status);
	ex->new_str = ft_strjoin_doblefree(ex->new_str, value);
	ex->i += len + 1;
}

void	expan(char **str, t_quotes *quote, t_shell *shell, int plus)
{
	t_expan	ex;
	char	*tmp;

	ex.new_str = ft_strdup("");
	ex.i = 0;
	ex.j = 0;
	if (plus == 1)
	{
		quote->quote_start++;
		quote->quote_end++;
	}
	while ((*str)[ex.i])
	{
		if ((*str)[ex.i] == '$' && !is_in_single_quote(ex.i, quote))
			process_dollar(&ex, str, quote, shell);
		else
		{
			tmp = ft_substr(*str, ex.i, 1);
			ex.new_str = ft_strjoin_free(ex.new_str, tmp);
			free(tmp);
			ex.i++;
		}
	}
	free(*str);
	*str = ex.new_str;
}

void	expancion_var(t_comand_data *cmd, t_shell *shell)
{
	int	i;

	i = 0;
	while (cmd->comand && cmd->comand[i])
	{
		if (ft_strchr(cmd->comand[i], '$'))
			expan(&cmd->comand[i], cmd->quote[i], shell, 0);
		i++;
	}
	i = 0;
	while (cmd->in_file && i < cmd->in_count)
	{
		if (ft_strchr(cmd->in_file[i], '$'))
			expan(&cmd->in_file[i], cmd->quote_in[i], shell, 1);
		i++;
	}
	i = 0;
	while (cmd->out_file && i < cmd->out_count)
	{
		if (ft_strchr(cmd->out_file[i], '$'))
			expan(&cmd->out_file[i], cmd->quote_out[i], shell, 1);
		i++;
	}
}
