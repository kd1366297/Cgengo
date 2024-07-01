#include<stdio.h>
void error_msg(void);

main()
{
	int a,b;
	printf("data1 data2:");
	scanf("%d%d", &a, &b);
	if (b == 0) {
		error_msg();
	}
	else {
		printf("%d/%d=%dEEE%d\n", a,b, a / b, a % b);
	}
}

void error_msg(void)
{
	printf("0‚ÅŠ„‚èZ‚Í‚Å‚«‚Ü‚¹‚ñ\n");
	return;
}
