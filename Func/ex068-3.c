#include<stdio.h>
main()
{
	int c;  //getchar関数は「入力終了」の場合にDOF(-1)を取り戻すため

	//連続1文字入力の定石パターン
	while ((c = getchar()) != EOF) {
		putchar(c);
		}
}
