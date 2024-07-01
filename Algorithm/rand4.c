#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int un, i;

	srand(time(0));
	rand();
	un = rand() % 5 + 1;

	printf("¡“ú‚Ì‚ ‚È‚½‚Ì‰^¨‚ÍA");
	for (i = 0; i < un; i++) {
		printf("™");
	}
	printf("‚Å‚·B\n");
}
