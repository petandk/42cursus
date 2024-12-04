/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:21:23 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/04 23:50:32 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_commands(t_command *comm)
{
	if (comm)
	{
		if (comm -> first_command)
			free (comm -> first_command);
		if (comm -> first_flags)
			free (comm -> first_flags);
		if (comm -> second_command)
			free (comm -> second_command);
		if (comm -> second_flags)
			free (comm -> second_flags);
		free (comm);
	}
}

static void	free_array(char **arr)
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
	char	**aux;

	aux = ft_split(arg, ' ');
	if (!aux)
		return (0);
	if (!is_second)
	{
		comm -> first_command = ft_strdup(aux[0]);
		if (aux[1])
			comm -> first_flags = ft_strdup(aux[1]);
		else
			comm -> first_flags = NULL;
	}
	else
	{
		comm -> second_command = ft_strdup(aux[0]);
		if (aux[1])
			comm -> second_flags = ft_strdup(aux[1]);
		else
			comm -> second_flags = NULL;
	}
	free_array(aux);
	return (1);
}

t_command	*ft_check_args(int argc, char **argv)
{
	t_command	*comm;

	if (argc != 5)
		return (NULL);
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
