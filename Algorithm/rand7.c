#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int a,b,cnt=0;

	srand(time(0));
	rand();
	a = rand() % 1000 + 1;
	printf("1〜1000の中で当たりの数を予想してください\n");
	do {
		printf("当たりの数は？->");
		scanf("%d", &b);
		if (a > b) {
			printf("当たりの数より小さいです");
		}
		if (a < b) {
			printf("当たりの数より大きいです\n");
		}
		cnt++;
	} while (a != b);
	printf("正解!%d回目で当たりました\n", cnt);
}
