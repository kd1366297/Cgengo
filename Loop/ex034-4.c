#include<stdio.h>
main()
{
	int i,j,num;
	printf("”‚Í?");
	scanf("%d", &num);

	i = 0;
	do
	{
		j = 0;
		do {
			printf(" ");
			j++;
		} while (j < num - i);
		j = 0;
		do {
			printf("*");
			j++;
		} while (j<i+1);

		printf("\n");
		i++;
	} while (i < num);
}
