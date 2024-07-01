#include<stdio.h>
main()
{
	int a, b, c, ret;
	printf("3‚Â‚Ì®”‚ğ‹ó”’‚Å‹æØ‚Á‚Ä“ü—Í:");
	ret = scanf("%d%d%d", &a, &b, &c);
	printf("ret=%d a=%d b=%d c=%d\n", ret, a, b, c);
	printf("®”‚ğ“ü—Í(Ctrl+Z‚ÅI—¹)a:");
		while (scanf("%d", &a) != EOF) {
			printf("a=%d\n", a);
			printf("®”‚ğ“ü—Í(Ctrl+Z‚ÅI—¹)a:");
		}
}
