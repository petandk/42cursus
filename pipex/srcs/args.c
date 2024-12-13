/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:21:23 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/13 20:59:02 by rmanzana         ###   ########.fr       */
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

static int	comm_path(char *cmd, char **argv, t_command *comm, int is_second)
{
	char	*last_part;
	char	*base;

	if (ft_strncmp(cmd, "./", 2) == 0)
	{
		free (cmd);
		if (!is_second)
			comm->first_argv = argv;
		else
			comm->second_argv = argv;
		return (1);
	}
	last_part = ft_strrchr(cmd, '/');
	if (last_part)
	{
		base = ft_strdup(last_part + 1);
		free(argv[0]);
		argv[0] = base;
		free(cmd);
	}
	return (0);
}

static int	parse_command(char *arg, t_command *comm, int is_second)
{
	char	**argv;
	char	*cmd;

	argv = ft_split(arg, ' ');
	if (!argv)
		return (0);
	cmd = ft_strdup(argv[0]);
	if (!cmd)
		return (free_array(argv), 0);
	if (cmd && (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/')))
	{
		if (comm_path(cmd, argv, comm, is_second))
			return (1);
	}
	else
		free(cmd);
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
		write(2, "ERROR: one or more empty commands\n", 34);
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
