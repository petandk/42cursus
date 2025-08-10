/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:31:39 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/29 18:17:38 by rmanzana         ###   ########.fr       */
/*   Updated: 2025/02/05 15:06:51 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_flag(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_echo(t_shell *shell, char **cmd)
{
	int	i;
	int	is_n;

	i = 1;
	is_n = 0;
	while (cmd[i] && is_flag(cmd[i]))
	{
		is_n = 1;
		i++;
	}
	while (cmd[i])
	{
		if (cmd[i][0] != '\0')
			ft_putstr_fd(cmd[i], 1);
		if (cmd[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!is_n)
		write(1, "\n", 1);
	shell->exit_status = 0;
}
