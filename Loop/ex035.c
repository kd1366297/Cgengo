#include<stdio.h>
main()
{
	int sum, num;
	sum = 0;
	while (1) {
		printf("”‚ğ“ü‚ê‚Ä:");
		scanf("%d", &num);
		if (num == -999)break;
		sum += num;
	}
	printf("‡Œv%d", sum);
}
