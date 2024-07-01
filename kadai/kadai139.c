#include<stdio.h>
void hyouzi(char moji, int n);
main()
{
	int n;
	char moji;
	printf("•¶š?:");
	scanf("%c", &moji);
	printf("®”?:");
	scanf("%d", &n);
	hyouzi(moji, n);
}
void hyouzi(char moji, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%c", moji);
	}
}

