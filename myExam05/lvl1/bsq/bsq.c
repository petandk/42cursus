#include "bsq.h"

static void free_map(char **map, int lines)
{
	if (map)
	{
		for (int y = 0; y < lines; y++)
			if (map[y])
				free(map[y]);
		free(map);
	}
}

static void free_matrix(int **matrix, int rows)
{
	if (matrix)
	{
		for (int y = 0; y < rows; y++)
			if (matrix[y])
				free(matrix[y]);
		free(matrix);
	}
}

static bool is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

static int validate_map(FILE *file, t_map *map)
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t nread;

	if (fscanf(file, "%d %c %c %c", &map->lines, &map->empty, &map->obstacle, &map->full) != 4)
		return 0;

	if (map->lines <= 0)
		return 0;

	if (!is_printable(map->empty) || !is_printable(map->obstacle) || !is_printable(map->full))
		return 0;

	if (map->empty == map->obstacle || map->obstacle == map->full || map->full == map->empty)
		return 0;

	map->map = calloc(map->lines, sizeof(char *));
	if (!map->map)
		return 0;

	getline(&buffer, &len, file);
	free(buffer);
	buffer = NULL;
	len = 0;

	for (int y = 0; y < map->lines; y++)
	{
		if ((nread = getline(&buffer, &len, file)) == -1)
			return (free(buffer),free_map(map->map, y), 0);

		if (nread > 0 && buffer[nread - 1] == '\n')
		{
			buffer[nread - 1] = '\0';
			nread--;
		}
		if (y == 0)
			map->length = nread;
		else if (nread != map->length)
			return (free(buffer), free_map(map->map, y), 0);

		for (int x = 0; x < nread; x++)
		{
			if (buffer[x] != map->empty && buffer[x] != map->obstacle)
				return (free(buffer), free_map(map->map, y), 0);
		}
		map->map[y] = buffer;
		buffer = NULL;
		len = 0;
	}
	return 1;
}

static int **allocate_matrix(int rows, int columns)
{
	int **matrix = calloc(rows, sizeof(int *));
	if (!matrix)
		return NULL;
	for (int y = 0; y < rows; y++)
	{
		matrix[y] = calloc(columns, sizeof(int));
		if (!matrix[y])
			return (free_matrix(matrix, y), NULL);
	}
	return matrix;
}

static int min(int a, int b)
{
	return (a < b) ? a : b;
}

static int solve_bsq(t_map *map)
{
	int size = 0;
	int row = 0;
	int col = 0;

	int **copy = allocate_matrix(map->lines, map->length);
	if (!copy)
		return 0;
	for (int y = 0; y < map->lines; y++)
	{
		for (int x = 0; x < map->length; x++)
		{
			if (map->map[y][x] == map->obstacle)
			{
				copy[y][x] = 0;
				continue;
			}
			if (y == 0 || x == 0)
				copy[y][x] = 1;
			else
				copy[y][x] = min(copy[y-1][x], min(copy[y][x-1], copy[y-1][x-1])) + 1;

			if (copy[y][x] > size)
			{
				size = copy[y][x];
				row = y;
				col = x;
			}
		}
	}
	for (int y = row - size + 1; y <= row; y++)
		for (int x = col - size + 1; x <= col; x++)
			map->map[y][x] = map->full;
	for (int y = 0; y < map->lines; y++)
	{
		fprintf(stdout, "%s\n", map->map[y]);
	}

	free_matrix(copy, map->lines);
	
	return 1;
}

static int bsq_from_file(FILE *file)
{
	t_map map;
	map.map = NULL;
	map.length = 0;
	map.lines = 0;

	if (!validate_map(file, &map))
		return (free_map(map.map, map.lines), -1);
	if (!solve_bsq(&map))
		return (free_map(map.map, map.lines), -1);
	free_map(map.map, map.lines);
	return 1;
}

static int bsq(char *filename)
{
	FILE *file = fopen(filename, "r");
	if (!file)
		return -1;
	int result = bsq_from_file(file);
	fclose(file);
	return result;
}

int main (int argc, char *argv[])
{
	if (argc == 1)
	{
		if (bsq_from_file(stdin) == -1)
			return(fputs("map error\n", stderr), 1);
		return 0;
	}
	for (int i = 1; i <argc; i++)
	{
		if (bsq(argv[i]) == -1)
			return(fputs("map error\n", stderr), 1);
		if (i < argc - 1)
			fputs("\n", stdout);
	}
	return 0;
}
