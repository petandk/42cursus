#include "bsq.h"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		if (bsq_from_file(stdin) == -1)
			fputs("map error\n", stderr);
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		if (bsq(argv[i]) == -1)
			fputs("map error\n", stderr);
		if (argc > 2)
			fputs("\n", stdout);
	}
	return 0;
}