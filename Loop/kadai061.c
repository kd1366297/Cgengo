#include<stdio.h>
main()
{
	int a = 1;
	do {
		if (a < 10) {
			printf(" %d ", a);
			a++;
			if (a % 10 == 1) {
				printf("\n");
			}
		}
		else {
			printf("%d ", a);
			a++;
				if (a % 10 == 1) {
					printf("\n");
				}
		}
	} while (a <= 20);
}
