#include<stdio.h>
main()
{
	int a;

	printf("整数(-1で入力終了)?");
	scanf("%d", &a);

	while (a != -999)
	{
		printf("8進数=%o ", a);
		printf("16進数=%x\n", a);

		printf("整数(-1で入力終了)?");
		scanf("%d", &a);
	}
}
