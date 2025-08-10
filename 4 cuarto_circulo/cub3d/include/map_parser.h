/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:19:18 by rmanzana          #+#    #+#             */
/*   Updated: 2025/07/31 18:58:53 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# include <stddef.h>

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_map
{
	char	*no_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*we_texture;
	int		c_color;
	int		f_color;
	char	**map;
	int		maprows;
	t_point	spawnpoint;
	char	spawn_dir;
}			t_map;

// header_validator.c

int			check_cardinals(char *line, t_map *map);
int			check_colors(char *line, t_map *map);
int			is_header(char *line, t_map *map);

// map_parser.c

char		*parse_header(int fd, t_map *map);
int			collect_map_data(char *start, int fd, t_list **maplist, t_map *map);
t_map		*parse_map_file(char *mapname);

// map_validate.c

int			validate_map(t_map *map);

// list_array_utils.c

char		**list_to_array(t_list *maplist, int maprows);
int			convert_list_to_map(t_list *maplist, t_map *map);
void		free_nodes_no_content(t_list *maplist);
void		cleanup_gnl(int fd);

// color_utils.c

int			charcolortoint(char *color);
int			set_texture_value(char *identifier, char **texture, char *line);
int			set_color_value(char *identifier, int *color, char *line);

// map_utils.c

void		map_init(t_map *map);
void		free_map(t_map *map);
void		clean_and_exit(int fd, t_map *map);

// string_utils.c

int			is_space(char c);
char		*skip_spaces(char *line);
int			is_empty(char *line);
char		**ft_free_array(char **split);
int			check_extension(char *filename, char *expected);

// int_utils.c

int			is_valid_number(char *str);

// debug.c

void		print_mapfile(t_map *map);
void		debug_show_textures(t_map *map);

#endif
