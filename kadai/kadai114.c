#include<stdio.h>
main()
{
	char moji[20];
	int cnt;

	printf("\n�������?");
	scanf("%s", &moji[0]);
	cnt = 0;
	while (moji[cnt] != '\0') {
		cnt++;
	}
	printf("������:%s ������:%d����\n", moji, cnt);
}
