#include<stdio.h>
main()
{
	int a[2][2][3] = {
	{{3,4,5}
	{ 4,5,6 }}
	{ { 2,2,3 }
	{ 2,5,6 }
}
	};
	int i, j, k, sum;

	for (sum = 0, i = 0; i < 2; i++) {
		printf("アパート%d", i + 1);
		for (j = 0; j < 2; j++) {
			printf("(%d階):", j + 1);
			for (k = 0; k < 3; k++) {
				printf("%d", a[i][j][k]);
				sum += a[i][j][k];
			}
		}
		printf("\n");
	}
	printf("全体で%d人住んでいます\n", sum);
}

