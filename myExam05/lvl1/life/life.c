#include "life.h"

static void init_game(t_game *game, char **argv)
{
	game->width = atoi(argv[1]);
	game->height = atoi(argv[2]);
	game->iterations = atoi(argv[3]);

	game->map = malloc(game->height * sizeof(char *));
	for (int y = 0; y < game->height; y++)
	{
		game->map[y] = malloc(game->width * sizeof(char));
		for(int x = 0; x < game->width; x++)
			game->map[y][x] = ' ';
	}
}

static void turtle(t_game *game)
{
	char	buffer;
	int		x = 0;
	int		y = 0;
	bool	draw = false;

	while(read(STDIN_FILENO, &buffer, 1) == 1)
	{
		switch(buffer)
		{
			case('w'): if (y > 0) y--; break;
			case('s'): if (y < game->height - 1) y++; break;
			case('a'): if (x > 0) x--; break;
			case('d'): if (x < game->width - 1) x++; break;
			case('x'): draw = !draw; break;
			default: continue;
		}
	
		if (draw && x >= 0 && x < game->width && y >= 0 && y < game->height)
		game->map[y][x] = '0';
	}
}

static int count_neighbors(t_game game, int y, int x)
{
	int count = 0;

	for (int ny = -1; ny < 2; ny++)
	{
		for (int nx = -1; nx <2; nx++)
		{
			if (ny == 0 && nx == 0)
				continue;

			int ax = x + nx;
			int ay = y + ny;

			if (ax >= 0 && ax < game.width && ay >= 0 && ay < game.height &&game.map[ay][ax] == '0')
				count++;
		}
	}
	return count;
}

static void free_map(t_game *game)
{
	if (game->map)
	{
		for (int y = 0; y < game->height; y++)
			if (game->map[y])
				free(game->map[y]);
		free(game->map);
	}
}

static void play_game(t_game *game)
{
	char **copy = malloc(game->height * sizeof(char *));
	for (int y = 0; y < game->height; y++)
		copy[y] = malloc(game->width * sizeof(char));

	for (int y = 0; y < game->height; y++)
	{
		for (int x = 0; x < game->width; x++)
		{
			int nei = count_neighbors(*game, y, x);

			if (game->map[y][x] == '0')
			{
				if (nei == 2 || nei == 3)
					copy[y][x] = '0';
				else
					copy[y][x] = ' ';
			}
			else
			{
				if (nei == 3)
					copy[y][x] = '0';
				else
					copy[y][x] = ' ';
			}
		}
	}
	free_map(game);
	game->map = copy;
}

static void print_map(t_game game)
{
	for (int y = 0; y < game.height; y++)
	{
		for (int x = 0; x < game.width; x++)
			putchar(game.map[y][x]);
		putchar('\n');
	}
}

int main (int argc, char *argv[])
{
	if (argc != 4)
		return 1;

	t_game game;

	init_game(&game, argv);
	turtle(&game);
	for (int i = 0; i < game.iterations; i++)
		play_game(&game);

	print_map(game);
	free_map(&game);

	return 0;
}
