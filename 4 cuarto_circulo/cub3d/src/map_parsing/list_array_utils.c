/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_array_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:50:13 by rmanzana          #+#    #+#             */
/*   Updated: 2025/07/31 16:50:15 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

/*
	converts linked list to char **array, transferring ownership
	move pointers from list noes to array without duplication
	returns NULL-terminated array or NULL on malloc failure
*/
char	**list_to_array(t_list *maplist, int maprows)
{
	char	**map;
	t_list	*current;
	int		i;

	map = malloc(sizeof(char *) * (maprows + 1));
	if (!map)
		return (NULL);
	current = maplist;
	i = 0;
	while (current && i < maprows)
	{
		map[i] = current->content;
		current = current->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

/*
	converts lined list to array and cleans up nodes
	final step to prepare map to use
*/
int	convert_list_to_map(t_list *maplist, t_map *map)
{
	map->map = list_to_array(maplist, map->maprows);
	if (!map->map)
		return (0);
	free_nodes_no_content(maplist);
	return (1);
}

/*
	free the node list but NOT the content.
	use afer list_to_array() to clean empty nodes
*/
void	free_nodes_no_content(t_list *maplist)
{
	t_list	*next;
	t_list	*current;

	current = maplist;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/*
	cleans remaining lines from get_next_line buffer
	ensures fd is fully consumed and cleaned
*/
void	cleanup_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}
