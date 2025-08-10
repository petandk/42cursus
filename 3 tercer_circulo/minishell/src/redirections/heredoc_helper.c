/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:23:03 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/17 19:00:24 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*single_heredoc(char *here, t_shell **shell, int exp, int last)
{
	t_list	*lines;

	lines = handle_heredoc(here + 1, shell, exp);
	if (!lines && last)
		return (NULL);
	if (!lines && errno == EINTR)
	{
		errno = EINTR;
		return (NULL);
	}
	return (lines);
}

static t_list	*heredoc_loop(char **split, int br, t_shell **shell, int exp)
{
	t_list	*lines;
	t_list	*result;
	int		i;

	lines = NULL;
	result = NULL;
	i = 0;
	br--;
	while (i <= br)
	{
		if (split[i] && (split[i][0] == '_' || split[i][0] == '-'))
		{
			lines = single_heredoc(split[i], shell, exp, (i == br));
			if (!lines && errno == EINTR)
				break ;
			if (i == br)
				result = lines;
			else if (lines)
				ft_lstclear(&lines, free);
			lines = NULL;
		}
		i++;
	}
	return (result);
}

static int	check_access(char **split, int brackets, t_shell **shell)
{
	int	i;

	i = 0;
	while (i <= brackets - 1)
	{
		if (split[i] && split[i][0] == '<')
		{
			if (access(split[i] + 1, F_OK) != 0)
			{
				printerror("no_file", split[i] + 1);
				(*shell)->exit_status = 1;
				return (1);
			}
		}
		i++;
	}
	return (0);
}

static t_list	*handle_cleanup(t_list *result)
{
	if (errno == EINTR)
	{
		if (result)
			ft_lstclear(&result, free);
		return (NULL);
	}
	return (result);
}

t_list	*ft_hdc_helper(char **split, int brackets, t_shell **shell, int expand)
{
	t_list	*result;
	int		old_errno;

	old_errno = errno;
	result = heredoc_loop(split, brackets, shell, expand);
	result = handle_cleanup(result);
	if (!result && errno == EINTR)
		return (NULL);
	if (check_access(split, brackets, shell))
	{
		if (result)
			ft_lstclear(&result, free);
		return (NULL);
	}
	errno = old_errno;
	return (result);
}
