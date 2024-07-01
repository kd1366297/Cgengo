#include<stdio.h>
main()
{
	int c;
	char dumy[256];

	c = getchar();
	while (c != EOF) {      //データの入力完了 ctrl+Z
		putchar(c);
		putchar('\n');
		gets(dumy);         //入力バッファのクリア
		c = getchar();
	}
}
