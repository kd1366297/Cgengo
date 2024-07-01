#include<stdio.h>
main()
{
	float ia, ib;
	printf("2‚Â‚ÌŽÀ”’lH");
	scanf("%f%f", &ia,&ib);
	if (ia > ib)
	{
		printf("‘å‚«‚¢‚Ù‚¤‚Í:%f\n", ia);
	}
	else
	{
		if (ia < ib)
		{
			printf("‘å‚«‚¢‚Ù‚¤‚Í:%f\n", ib);
		}
		else {
			printf("“¯’l‚Å‚·");
		}
	}
}
