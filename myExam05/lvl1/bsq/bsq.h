#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <unistd.h>


typedef struct map
{
	char	**map;
	int		lines_num;
	int		line_length;
	char	empty;
	char	obstacle;
	char	full;
} map;

int bsq_from_file(FILE *map_file);
int bsq(char *map_filename);

#endif