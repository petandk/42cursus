#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct
{
	char	**map;
	int		lines;
	int		length;
	char	empty;
	char	obstacle;
	char	full;
} t_map;
