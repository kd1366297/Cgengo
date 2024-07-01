#include<stdio.h>

int gokei(int, int, int);
float heikin(int, int, int);

main()
{
	int d1, d2, d3;
	printf("®”‚ğ3‚Â“ü—Í:");
	scanf("%d%d%d", &d1, &d2, &d3);

	printf("‡Œv‚Í %dA•½‹Ï‚Í%.2f\n", gokei(d1, d2, d3), heikin(d1, d2, d3));
}
int gokei(int d1, int d2, int d3)
{
	return d1 + d2 + d3;
}
float heikin(int d1, int d2, int d3)
{
	return(float)gokei(d1, d2, d3) / 3;
}