/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:10:44 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/04 23:50:12 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdlib.h>
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
t_command	*ft_check_args(int argc, char **argv);

#endif
