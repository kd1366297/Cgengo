#include<stdio.h>
main()
{
	char moji;
	moji = 'a';
	printf("子文字入力:");
	scanf("%c", &moji);
	printf("大文字に変換して=%c\n",moji-0x20);
}
