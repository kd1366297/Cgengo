#include<stdio.h>
main()
{
	int n;

	printf("整数？");
	scanf("%d", &n);

	if (n < 0) {
		printf("入力値はマイナスです\n");
	}
	else {
		printf("入力値はプラスです\n");
	}
}
