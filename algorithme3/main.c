#include "hashtable.h"
#include <time.h>

int		main(int argc, char **argv)
{
	clock_t start, end;

	if (argc < 2)
		exit(0);
	start=clock();
	//purgeJaroWinkler(argv[1]);
	//purgeLevenshtein(argv[1]);
	//purgeSoundex(argv[1]);
	//purge_N_Gram(argv[1]);
	end=clock();
	printf("%ld", end-start);
	return (0);
}