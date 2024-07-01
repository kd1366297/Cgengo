#include<stdio.h>
main()
{
	int a=50,b=10,c;
	int* p_a=&a,*p_b=&b;
	c = *p_a + *p_b;//c = a + b ‚Æ“¯‚¶
	printf("%d + %d = %d\n", *p_a, *p_b, c);
}
