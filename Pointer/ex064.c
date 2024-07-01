#include<stdio.h>
main()
{
	char* p_ride[3] = { "car","bus","shinkansen" },*cp;
	int i;

	for (i = 0; i < 3; i++) {
		cp = p_ride[i];
		while (*cp) {
			printf("%c", *cp++);
		}
		printf("\n");
	}
}
