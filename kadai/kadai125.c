#include<stdio.h>
main()
{
	int data[10] = { 10,20,30,40,50,60,70,80,-999 };
	int* p_d, * P_d;

	printf("�|�C���^���Œ�ŕ\��\n�z�� data[]=");
	p_d = data;
	for (int i = 0; data[i] != -999; i++) {
		p_d = data;
		p_d += i;
		printf("%2d,", *p_d);
	}
	printf("\n�|�C���^��ω������ĕ\��\n�z�� data[]=");
	P_d = data;

	while (*P_d != -999) {
		printf("%2d,", *P_d);
		P_d++;
	}
}
