#include<stdio.h>
main()
{
	char moji;
	moji = 'a';
	printf("�q��������:");
	scanf("%c", &moji);
	printf("�啶���ɕϊ�����=%c\n",moji-0x20);
}
