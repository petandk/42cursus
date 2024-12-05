/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:10:44 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/05 16:35:35 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef enum s_bool
{
	false,
	true
}	t_bool;

typedef struct s_command
{
	char	*infile;
	char	*first_command;
	char	*first_flags;
	char	*second_command;
	char	*second_flags;
	char	*outfile;

}	t_command;

void		free_commands(t_command *comm);
void		free_array(char **arr);
t_command	*ft_check_args(int argc, char **argv);
char		*get_path(char *command);
int			exec_comms(t_command *comm);
#endif
