#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int a,b,cnt=0;

	srand(time(0));
	rand();
	a = rand() % 1000 + 1;
	printf("1�`1000�̒��œ�����̐���\�z���Ă�������\n");
	do {
		printf("������̐��́H->");
		scanf("%d", &b);
		if (a > b) {
			printf("������̐���菬�����ł�");
		}
		if (a < b) {
			printf("������̐����傫���ł�\n");
		}
		cnt++;
	} while (a != b);
	printf("����!%d��ڂœ�����܂���\n", cnt);
}
