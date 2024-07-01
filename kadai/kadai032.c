#include<stdio.h>
main()
{
	int ia, amari;
	printf("整数値？");
	scanf("%d", &ia);
	amari = ia % 2;
	if (amari != 1)
	{
		printf("その数は「偶数」です");
	}
	else
	{
		printf("その数は「奇数」です");
	}
}
