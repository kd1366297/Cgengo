#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int p,c;

	srand(time(0));
	rand();
	printf("何を出しますか?\n(1:グー 2:チョキ 3:パー)>");
	scanf("%d", &p);

	c = rand() % 3;

	switch (p) {
	case 1:
		printf("\nプレイヤーは、グーです。\n");
		break;
	case 2:
		printf("\nプレイヤーは、チョキです。\n");
		break;
	case 3:
		printf("\nプレイヤーは、パーです。\n");
	}
	switch (c) {
	case 0:
		printf("\nコンピュータは、グーです。\n");
		break;
	case 1:
		printf("\nコンピュータは、チョキです。\n");
		break;
	case 2:
		printf("\nコンピュータは、パーです。\n");
	}
	switch (((p - 1) - c + 3) % 3) {
	case 0:
		printf("\nあいこです。\n");
		break;
	case 1:
		printf("\nコンピュータの勝ちです。\n");
		break;
	case 2:
		printf("\nプレイヤーの勝ちです。\n");
	}
}
