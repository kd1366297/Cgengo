#include<stdio.h>
main()
{
	int a;

	printf("����(-1�œ��͏I��)?");
	scanf("%d", &a);

	while (a != -999)
	{
		printf("8�i��=%o ", a);
		printf("16�i��=%x\n", a);

		printf("����(-1�œ��͏I��)?");
		scanf("%d", &a);
	}
}
