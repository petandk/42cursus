/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:09:54 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/04 23:46:08 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	t_command	*com;

	com = ft_check_args(argc, argv);
	if (!com)
		return (0);
	else
	{
		ft_printf("infile: %s\n", com->infile);
		ft_printf("com1: %s ", com ->first_command);
		ft_printf("flags1: %s\n", com->first_flags);
		ft_printf("com2: %s ", com->second_command);
		ft_printf("flags2: %s\n", com->second_flags);
		ft_printf("outfile: %s\n", com->outfile);
		free(com -> first_command);
		free(com -> first_flags);
		free(com -> second_command);
		free(com -> second_flags);
		free(com);
	}
	return (0);
}
