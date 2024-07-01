#include<stdio.h>
main()
{
	char moji;
	printf("1文字入力");
	scanf("%c", &moji);
	if ((moji >= 'A' && moji <= 'Z') || (moji >= 'a' && moji <= 'z'))
	{
		printf("アルファベットです");
	}
	else {
		printf("ERROR\n");
	}
}
