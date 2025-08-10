/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:40:01 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 16:40:27 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

/*
	checks for whitespace chars.
	returns 1 for space, 0 for other.
*/
int	is_space(char c)
{
	if ((c == 32) || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

/*
	skips whitespaces at the beggining of strings.
	returns pointer to first no whitespace char.
*/
char	*skip_spaces(char *line)
{
	while (is_space(line[0]))
		line++;
	return (line);
}

/*
	checks for only whitespace or empty line.
	returns 1 if empty/whitespace-only, 0 for other content
*/
int	is_empty(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && is_space(line[i]))
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}

/*
	frees an array of strings and its contents
	returns NULL for convenient pointer reset
*/
char	**ft_free_array(char **split)
{
	size_t	pos;

	pos = 0;
	while (split[pos] != NULL)
	{
		free(split[pos]);
		pos++;
	}
	free(split);
	return (NULL);
}

/*
	compares a filename extension with a specified one.
	returns 1 if they match, 0 if not.
	Ex. check_extension("north.xpm", ".xpm") returns 1
	filename + file_len - exp_len -> goes to the end of filename,
									then goes back exp_len characters
*/
int	check_extension(char *filename, char *expected)
{
	int	file_len;
	int	exp_len;

	if (!filename || !expected)
		return (0);
	file_len = ft_strlen(filename);
	exp_len = ft_strlen(expected);
	if (file_len < exp_len)
		return (0);
	return (ft_strncmp(filename + file_len - exp_len, expected, exp_len) == 0);
}
