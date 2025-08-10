/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:07:50 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/16 18:44:50 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execution(char *str, t_token **token, int size_token, t_shell *shell)
{
	t_comand_data	*comand;
	int				num_comands;

	num_comands = prepare_to_execute(&comand, (*token), size_token);
	free_t(str, token, size_token);
	if (num_comands <= 0)
		return (-1);
	shell->commands = comand;
	shell->num_commands = num_comands;
	execute_pipeline(comand, num_comands, shell);
	free_comand(comand, num_comands);
	return (1);
}
