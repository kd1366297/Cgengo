#include<stdio.h>
main()
{
	int su1, su2, su3, gokei;
	printf("������3����:");
	scanf("%d%d%d", &su1, &su2, &su3);
	gokei = su1 + su2 + su3;

	printf("���v= %d",gokei);//���v
	//printf("����= %.2f",gokei/3.0);//����
	printf("����= %.2f", (float)gokei / 3);//����
}