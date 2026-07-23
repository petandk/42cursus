#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int		height;
	int		width;
	int		iterations;
	char	**map;
}	t_game;
