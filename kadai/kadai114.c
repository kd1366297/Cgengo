#include<stdio.h>
main()
{
	char moji[20];
	int cnt;

	printf("\n文字列は?");
	scanf("%s", &moji[0]);
	cnt = 0;
	while (moji[cnt] != '\0') {
		cnt++;
	}
	printf("文字列:%s 文字数:%d文字\n", moji, cnt);
}
