/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:46:54 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/04 23:51:28 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	t_command	*comm;

	comm = ft_check_args(argc, argv);
	if (!comm)
		return (0);
	else
	{

		free_commands(comm);
	}
	return (0);
}
