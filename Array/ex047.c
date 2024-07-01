#include<stdio.h>
main()
{
	float x[3][2],sum;
	int i,j;

	for(i=0;i<3;i++){
		for (sum = 0, j = 0; j < 2; j++) {
			printf("x[%d][%d]=", i, j);
			scanf("%f", &x[i][j]);
				sum += x[i][j];
		}
		printf("%ds–Ú‚Ì•½‹Ï= %.2f\n\n",i, sum / 2);
	}
}
