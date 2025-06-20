/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:37:48 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/16 18:13:03 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_no_val_export(t_shell *shell, char *arg)
{
	t_env	*exists;
	t_env	*new_var;

	if (!is_valid_name(arg))
	{
		multend_fd("export: ", arg, ": not a valid identifier", 2);
		return (1);
	}
	exists = find_env_var(shell->env, arg);
	if (exists)
		return (0);
	else
	{
		new_var = env_lstnew(arg, NULL);
		if (!new_var)
			return (1);
		env_lstadd_back(&shell->env, new_var);
		return (0);
	}
}
