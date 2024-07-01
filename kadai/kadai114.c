#include<stdio.h>
main()
{
	char moji[20];
	int cnt;

	printf("\n•¶š—ñ‚Í?");
	scanf("%s", &moji[0]);
	cnt = 0;
	while (moji[cnt] != '\0') {
		cnt++;
	}
	printf("•¶š—ñ:%s •¶š”:%d•¶š\n", moji, cnt);
}
