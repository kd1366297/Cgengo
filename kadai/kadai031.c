#include<stdio.h>
main()
{
	float ia, ib;
	printf("2�̎����l�H");
	scanf("%f%f", &ia,&ib);
	if (ia > ib)
	{
		printf("�傫���ق���:%f\n", ia);
	}
	else
	{
		if (ia < ib)
		{
			printf("�傫���ق���:%f\n", ib);
		}
		else {
			printf("���l�ł�");
		}
	}
}
