/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:21:23 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/12 16:05:07 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_commands(t_command *comm)
{
	if (comm)
	{
		if (comm -> first_argv)
			free_array(comm -> first_argv);
		if (comm -> second_argv)
			free_array(comm -> second_argv);
		free(comm);
	}
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}

static int	parse_command(char *arg, t_command *comm, int is_second)
{
	char	**argv;

	argv = ft_split(arg, ' ');
	if (!argv)
		return (0);
	if (!is_second)
		comm->first_argv = argv;
	else
		comm->second_argv = argv;
	return (1);
}

t_command	*ft_check_args(int argc, char **argv)
{
	t_command	*comm;

	if (argc != 5)
		return (NULL);
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		ft_printf("ERROR: invalid commands\n");
		return (NULL);
	}
	comm = (t_command *)malloc(sizeof(t_command));
	if (!comm)
		return (NULL);
	comm -> infile = argv[1];
	if (!parse_command(argv[2], comm, 0))
		return (free (comm), NULL);
	if (!parse_command(argv[3], comm, 1))
		return (free_commands(comm), NULL);
	comm->outfile = argv[4];
	return (comm);
}
