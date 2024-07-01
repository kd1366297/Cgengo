#include<stdio.h>
main()
{
	int a = 100, b = 200, w;
	int* p_a = &a, * p_b = &b;
	printf("Às‘O:a=%d\tb=%d\n", a, b);
	w = *p_a;    //w = a ‚Æ“¯‚¶
	*p_a = *p_b; //a = b ‚Æ“¯‚¶
	*p_b = w;    //b = w ‚Æ“¯‚¶
	printf("ÀsŒã:a=%d\tb=%d\n", a, b);
}
