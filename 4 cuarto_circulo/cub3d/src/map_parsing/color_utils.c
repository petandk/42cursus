/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:49:54 by rmanzana          #+#    #+#             */
/*   Updated: 2025/07/31 16:50:00 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

/*
	Format: (Alpha << 24) | (r << 16) | (g << 8) | b
	returns 0 on invalid input or outside 0-255 range
*/
int	charcolortoint(char *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(color, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (ft_free_array(rgb), 0);
	if (!is_valid_number(rgb[0]) || !is_valid_number(rgb[1])
		|| !is_valid_number(rgb[2]))
		return (ft_free_array(rgb), 0);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_free_array(rgb);
	if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255))
		return ((255 << 24) | (r << 16) | (g << 8) | b);
	return (0);
}

/*
	processes and validates texture path string
	returns clean and allocated path string or NULL on error
*/
static char	*process_texture_path(char *raw, int *error_code)
{
	char	*texture;
	int		len;

	texture = ft_strdup(raw);
	if (!texture)
		return (NULL);
	len = ft_strlen(texture);
	if (len > 0 && texture[len - 1] == '\n')
		texture[len - 1] = '\0';
	if (texture[0] == '\0')
	{
		free(texture);
		*error_code = 0;
		return (NULL);
	}
	if (!check_extension(texture, ".xpm"))
	{
		free(texture);
		*error_code = 3;
		return (NULL);
	}
	return (texture);
}

/*
	sets texture path for identifier (NO,SO, WE, EA)
	0 -> identifier not it line
	1 -> set_texture_value success
	2 -> already set (duplicate texture)
	3 -> invalid file extension
*/
int	set_texture_value(char *identifier, char **texture, char *line)
{
	char	*temp;
	int		error_code;
	int		i;

	error_code = 0;
	if (!ft_strncmp(line, identifier, 2))
	{
		if (*texture != NULL)
			return (2);
		temp = skip_spaces(line + 2);
		i = 0;
		while (temp[i] && !is_space(temp[i]))
			i++;
		temp[i] = '\0';
		if (!temp || temp[0] == '\0')
			return (0);
		*texture = process_texture_path(temp, &error_code);
		if (!*texture)
			return (error_code);
		return (1);
	}
	return (0);
}

/*
	sets color value for floor (F) or ceiling (C)
	0 -> identifier not it line
	1 -> set_color_value success
	2 -> already set (duplicate texture)
	4 -> invalid color
*/
int	set_color_value(char *identifier, int *color, char *line)
{
	char	*color_str;
	char	*comment_pos;
	int		len;

	if (!ft_strncmp(line, identifier, 1))
	{
		if (*color != 0)
			return (2);
		color_str = skip_spaces(line + 1);
		comment_pos = ft_strchr(color_str, '#');
		if (comment_pos)
			*comment_pos = '\0';
		len = ft_strlen(color_str);
		if (len > 0 && color_str[len - 1] == '\n')
			color_str[len - 1] = '\0';
		*color = charcolortoint(color_str);
		if (*color == 0)
			return (4);
		return (1);
	}
	return (0);
}
