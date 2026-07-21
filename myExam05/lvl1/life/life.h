#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct
{
	int		width;
	int		height;
	int		iterations;
	char	**map;
}	t_game;
