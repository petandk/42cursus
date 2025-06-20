/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:48:45 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/12 08:50:34 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_quotes(t_token *tk, int index)
{
	if (!tk || !tk[index].str)
		return (0);
	return (tk[index].quote_count > 0);
}

static char	*get_redirection_str(t_token *tk, int pos, int flag, char *rdt)
{
	if (ft_strcmp(rdt, "-") == 0)
	{
		if (has_quotes(tk, pos + 1))
			return (init_str("_", tk, pos, flag));
		else
			return (init_str("-", tk, pos, flag));
	}
	return (init_str(rdt, tk, pos, flag));
}

void	process_redirection(t_token *tk, t_comand_data *cmd,
			int *idx, char *rdt)
{
	char	*str;

	str = NULL;
	if (tk[idx[2]].str == NULL && rdt)
	{
		str = get_redirection_str(tk, idx[2], idx[3], rdt);
		if (ft_strcmp(rdt, ">") == 0 || ft_strcmp(rdt, "_") == 0)
			process_output_redirection(cmd, tk, idx, str);
		else
			process_input_redirection(cmd, tk, idx, str);
		free(str);
	}
}

int	the_files(t_ind *ind, int size, t_token *tk, t_comand_data **cmd)
{
	int		idx[4];

	idx[0] = 0;
	idx[1] = 0;
	idx[3] = size;
	in_out_size(&(*cmd)[ind->j], *ind, size, tk);
	init_int_out(&(*cmd)[ind->j], (*cmd)[ind->j].in_count,
		(*cmd)[ind->j].out_count);
	while (ind->i < size && !tk[ind->i].pipe)
	{
		if (!tk[ind->i].str && ind->i + 1 < size && tk[ind->i + 1].str)
		{
			idx[2] = ind->i;
			if (tk[ind->i].greater_than)
				process_redirection(tk, &(*cmd)[ind->j], idx, ">");
			else if (tk[ind->i].double_greater)
				process_redirection(tk, &(*cmd)[ind->j], idx, "_");
			else if (tk[ind->i].less_than)
				process_redirection(tk, &(*cmd)[ind->j], idx, "<");
			else if (tk[ind->i].double_less)
				process_redirection(tk, &(*cmd)[ind->j], idx, "-");
		}
		ind->i++;
	}
	return (1);
}
