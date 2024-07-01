#include<stdio.h>
main()
{
	int a[10] = { 10,20,30,40,50,60,70,80,90,100 };
	int b[10] = { 100,200,300,400,500,600,700,800,900,1000 }, c[10] = {};
	int i;

	int sumA = 0;
	int sumB = 0;
	

	printf("配列a = ");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
		sumA += a[i];
	}
	
	printf("\n合計＝ %d\t平均＝ %d", sumA, sumA / 10);
	
	printf("\n配列b = ");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", b[i]);
		sumB += b[i];
	}

	printf("\n合計＝ %d\t平均＝ %d", sumB, sumB / 10);


}
