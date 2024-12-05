/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:46:54 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/05 16:32:10 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	t_command	*comm;
	int			success;
	
	comm = ft_check_args(argc, argv);
	if (!comm)
		return (0);
	else
	{
		success = exec_comms(comm);
		if (success != 0)
		{
			ft_printf("Failed to execute command\n");
			return (EXIT_FAILURE);
		}
		free_commands(comm);
	}
	return (EXIT_SUCCESS);
}
