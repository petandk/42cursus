/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:50:18 by rmanzana          #+#    #+#             */
/*   Updated: 2025/07/31 16:50:19 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

/*
	checks a line for spawn characters (N, S, E or W)
	0 = NOT found
	1 = Found
	-1 = more than one character (wrong map)
*/
int	check_spawnpoint(char *line, t_map *map)
{
	int		col;
	char	*spawn_chars;
	char	*direction;

	spawn_chars = "NSEW";
	col = 0;
	while (line[col])
	{
		direction = ft_strchr(spawn_chars, line[col]);
		if (direction)
		{
			if (map->spawn_dir != '\0')
				return (show_error("spawn"), -1);
			map->spawnpoint.x = col;
			map->spawnpoint.y = map->maprows;
			map->spawn_dir = line[col];
			return (1);
		}
		col++;
	}
	return (0);
}

static int	process_header_line(char **line, t_map *map, int *counter)
{
	int	header_result;

	header_result = is_header(*line, map);
	if (header_result == 1 && !is_empty(*line))
		(*counter)++;
	return (header_result);
}

/*
	parses header section of map file
	returns first non-header line or null on error
*/
char	*parse_header(int fd, t_map *map)
{
	char	*line;
	int		result[2];

	result[0] = 0;
	line = get_next_line(fd);
	while (line)
	{
		result[1] = process_header_line(&line, map, &result[0]);
		if (result[1] == 1)
		{
			free(line);
			line = get_next_line(fd);
		}
		else if (result[1] == 2)
			return (show_error("bad_header"), free(line), NULL);
		else if (result[1] == 3)
			return (show_error("bad_texture"), free(line), NULL);
		else if (result[1] == 4)
			return (show_error("bad_color"), free(line), NULL);
		else
			break ;
	}
	if (result[0] < 6)
		return (show_error("miss_header"), free(line), NULL);
	return (line);
}

/*
	collects map data, counts rows,
		finds spawn point and validates spawn existence
*/
int	collect_map_data(char *start, int fd, t_list **maplist, t_map *map)
{
	t_list	*new_node;
	int		spawn_result;

	while (start)
	{
		spawn_result = check_spawnpoint(start, map);
		if (spawn_result == -1)
			return (free(start), ft_lstclear(maplist, free), 0);
		new_node = ft_lstnew(start);
		if (!new_node)
			return (free(start), ft_lstclear(maplist, free), 0);
		ft_lstadd_back(maplist, new_node);
		start = get_next_line(fd);
		map->maprows++;
	}
	if (start)
		free(start);
	if (map->spawn_dir == '\0')
		return (show_error("no_spawn"), 0);
	return (1);
}

/*
	main parsing function
	opens file
	parses header
	parses map data
	converts to final format
	returns t_map pointer -> NEEDS TO BE FREED!
*/
t_map	*parse_map_file(char *mapname)
{
	int		fd;
	char	*line;
	t_map	*map;
	t_list	*maplist;

	maplist = NULL;
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		return (show_error("fd"), NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (close(fd), NULL);
	map_init(map);
	line = parse_header(fd, map);
	if (!line)
		return (clean_and_exit(fd, map), NULL);
	if (!collect_map_data(line, fd, &maplist, map))
		return (clean_and_exit(fd, map), ft_lstclear(&maplist, free), NULL);
	if (!convert_list_to_map(maplist, map))
		return (clean_and_exit(fd, map), ft_lstclear(&maplist, free), NULL);
	if (!validate_map(map))
		return (clean_and_exit(fd, map), NULL);
	cleanup_gnl(fd);
	close(fd);
	return (map);
}
