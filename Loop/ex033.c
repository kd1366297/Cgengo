#include<stdio.h>
main()
{
	int i, num, sum;
	printf("”‚Í?");
	scanf("%d", &num);

	for (sum = 0, i = 0; num != -999; i++)
	{
		sum += num;
		printf("”‚Í?");
		scanf("%d", &num);
	}

		printf("‡Œv=%d\n•½‹Ï=%.2f\n", sum, (float)sum / i);

}
