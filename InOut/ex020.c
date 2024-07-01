#include<stdio.h>
main()
{
	char moji;
	moji = 'a';
	printf("Žq•¶Žš“ü—Í:");
	scanf("%c", &moji);
	printf("‘å•¶Žš‚É•ÏŠ·‚µ‚Ä=%c\n",moji-0x20);
}
