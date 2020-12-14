#include "set.h"
#include <time.h>

int		main(int argc, char *argv[])
{
	int number_of_lines;
	clock_t start;
	clock_t end;

	if (argc < 2)
		exit(0);
	start = clock();
	purgeJaroWinkler(argv[1]);
	end=clock();
	printf("%ld\n", end-start);
	start = clock();
	purgeLevenshtein(argv[2]);
	end=clock();
	printf("%ld\n", end-start);
	start = clock();
	purgeSoundex(argv[3]);
	end=clock();
	printf("%ld\n", end-start);
	start = clock();
	purge_N_Gram(argv[4]);
	end=clock();
	printf("%ld\n", end-start);
	return 0;
}