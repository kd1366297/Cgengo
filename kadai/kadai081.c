#include<stdio.h>
main()
{
	int s, n, h;
	s = h = 0;
	while (1) {
		printf("®”:");
		scanf("%d", &n);
		if (n == -999) {
			break;
		}
			s += n;
			h++;
	}
	printf("‡Œv = %d\n•½‹Ï = %.2f\n", s, (float)s / h);
}
