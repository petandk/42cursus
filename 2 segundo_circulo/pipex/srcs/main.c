/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:46:54 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/17 19:06:19 by rmanzana         ###   ########.fr       */
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
		if (success == 2)
			return (free_commands(comm), EXIT_FAILURE);
		if (success == 1)
		{
			free_commands(comm);
			return (EXIT_FAILURE);
		}
		free_commands(comm);
	}
	return (EXIT_SUCCESS);
}
