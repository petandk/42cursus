#include "bsq.h"

void free_map(map *mp)
{
	if (mp->map)
	{
		for (int i = 0; i < mp->lines_num; i++)
			free(mp->map[i]);
	}
	free(mp->map);
}

bool	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int validate_map(FILE *map_file, map *mp)
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t nread;

	if (fscanf(map_file, "%d%c%c%c", &mp->lines_num, &mp->empty, &mp->obstacle, &mp->full) != 4)
		return 0;

	if (mp->lines_num <= 0)
		return 0;

	if (!is_printable(mp->empty) || !is_printable(mp->obstacle) || !is_printable(mp->full))
		return 0;

	if (mp->empty == mp->obstacle || mp->obstacle == mp->full || mp->full == mp->empty)
		return 0;

	mp->map = calloc(mp->lines_num, sizeof(char *));
	if (!mp->map)
		return 0;

	getline(&buffer, &len, map_file);
	free(buffer);
	buffer = NULL;
	len = 0;

	for (int i = 0; i < mp->lines_num; i++)
	{
		if ((nread = getline(&buffer, &len, map_file)) == -1)
			return free(buffer), 0;

		if (nread > 0 && buffer[nread - 1] == '\n')
		{
			buffer[nread - 1] = '\0';
			nread--;
		}
		if (i == 0)
			mp->line_length = nread;
		else if (nread != mp->line_length)
			return free(buffer), 0;

		for (int j = 0; j < nread; j++)
		{
			if (buffer[j] != mp->empty && buffer[j] != mp->obstacle)
				return free(buffer), 0;
		}

		mp->map[i] = buffer;
		buffer = NULL;
		len = 0;
	}
	return 1;
}

static int is_square_valid(map *mp, int row, int col, int size)
{
	for (int i = row; i < row + size; i++)
	{
		for (int j = col; j < col + size; j++)
		{
			if (mp->map[i][j] == mp->obstacle)
				return 0;
		}
	}
	return 1;
}

static int try_size(map *mp, int size, int *best_row, int *best_col)
{
	int found = 0;

	for (int i = 0; i + size <= mp->lines_num && !found; i++)
	{
		for (int j = 0; j + size <= mp->line_length; j++)
		{
			if (is_square_valid(mp, i, j, size))
			{
				*best_row = i;
				*best_col = j;
				found = 1;
				break;
			}
		}
	}
	return found;
}

int solve_bsq(map *mp)
{
	int best_size = 0;
	int best_row = 0;
	int best_col = 0;
	int max_possible = mp->lines_num < mp->line_length
		? mp->lines_num : mp->line_length;

	for (int size = 1; size <= max_possible; size++)
	{
		int row, col;

		if (!try_size(mp, size, &row, &col))
			break;
		best_size = size;
		best_row = row;
		best_col = col;
	}

	for (int i = best_row; i < best_row + best_size; i++)
		for (int j = best_col; j < best_col + best_size; j++)
			mp->map[i][j] = mp->full;

	for (int i = 0; i < mp->lines_num; i++)
	{
		fputs(mp->map[i], stdout);
		fputs("\n", stdout);
	}

	return 1;
}

int bsq_from_file(FILE *map_file)
{
	map mp;
	mp.map = NULL;
	mp.line_length = 0;
	mp.lines_num = 0;

	if (!validate_map(map_file, &mp))
	{
		free_map(&mp);
		return -1;
	}
	if (!solve_bsq(&mp))
	{
		free_map(&mp);
		return -1;
	}
	free_map(&mp);
	return 1;
}

int bsq(char *map_filename)
{
	FILE *map_file = fopen(map_filename, "r");
	if (!map_file)
		return -1;
	int result = bsq_from_file(map_file);
	fclose(map_file);
	return result;
}
