#include<stdio.h>
main()
{
	int d1, d2, flg;

	printf("‰‰Zq‚ğ“ü—Í:");
	scanf("%d", &flg);

	printf("‚Q‚Â‚Ì®”‚ğ“ü—Í:");
	scanf("%d%d", &d1, &d2);

	if (flg == 1) {
		printf("%d\n", d1 + d2);
	}
	else {
		if (flg == 2) {
			printf("%d\n", d1 - d2);
		}
		else {
			if (flg == 4) {
				printf("%d\n", d1 / d2);
			}
		}
	}
}
