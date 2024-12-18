/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:56:20 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/18 21:15:22 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *error_type, char *file)
{
	char	*message;

	message = NULL;
	if (ft_strncmp(error_type, "no file", 7) == 0)
	{
		write(2, "No such file or directory: ", 27);
		write(2, file, ft_strlen(file));
	}
	else if (ft_strncmp(error_type, "bad_fd", 6) == 0)
		write(2, "Bad file descriptor", 19);
	else if (ft_strncmp(error_type, "cmd_not_found", 13) == 0)
	{
		write(2, "Command not found: ", 19);
		write(2, file, ft_strlen(file));
	}
	else if (ft_strncmp(error_type, "perm_denied", 11) == 0)
		write(2, "Permission denied", 17);
	else if (ft_strncmp(error_type, "resource", 8) == 0)
		write(2, "Resource temporarily unavailable", 32);
	else if (ft_strncmp(error_type, "no_mem", 6) == 0)
		write(2, "Cannot allocate memory", 22);
	write(2, "\n", 1);
}
