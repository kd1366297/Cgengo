#include<stdio.h>
main()
{
	int data[10] = { 10,20,30,40,50,60,70,80,-999 };
	int* p_d, * P_d;

	printf("ポインタを固定で表示\n配列 data[]=");
	p_d = data;
	for (int i = 0; data[i] != -999; i++) {
		p_d = data;
		p_d += i;
		printf("%2d,", *p_d);
	}
	printf("\nポインタを変化させて表示\n配列 data[]=");
	P_d = data;

	while (*P_d != -999) {
		printf("%2d,", *P_d);
		P_d++;
	}
}
