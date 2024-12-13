/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:10:44 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/13 20:42:45 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_command
{
	char	*infile;
	char	**first_argv;
	char	**second_argv;
	char	*outfile;

}	t_command;

t_command	*ft_check_args(int argc, char **argv);
void		free_commands(t_command *comm);
void		free_array(char **arr);
char		*get_path(char *command);
int			exec_comms(t_command *comm);
void		print_error(char *error_type);

#endif
