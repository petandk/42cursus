/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:43:52 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/15 21:08:42 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*shell_init(char **envp)
{
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	if (!shell)
		exit (1);
	shell->commands = NULL;
	shell->num_commands = 0;
	shell->exit_status = 0;
	shell->pids = NULL;
	shell->env = NULL;
	shell->env = create_env_list(envp);
	if (!shell->env)
	{
		free(shell);
		exit (1);
	}
	return (shell);
}

void	cleanup_shell(t_shell **shell)
{
	if (!shell || !*shell)
		return ;
	if ((*shell)->env)
		clear_env_list(&(*shell)->env);
	if ((*shell)->commands && (*shell)->num_commands > 0)
	{
		free_comand((*shell)->commands, (*shell)->num_commands);
		(*shell)->commands = NULL;
		(*shell)->num_commands = 0;
	}
	if ((*shell)->pids)
	{
		free((*shell)->pids);
		(*shell)->pids = NULL;
	}
	free(*shell);
	*shell = NULL;
}
