#include<stdio.h>
main()
{
	char moji;
	printf("1��������");
	scanf("%c", &moji);
	if ((moji >= 'A' && moji <= 'Z') || (moji >= 'a' && moji <= 'z'))
	{
		printf("�A���t�@�x�b�g�ł�");
	}
	else {
		printf("ERROR\n");
	}
}
