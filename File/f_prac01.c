#include<stdio.h>
main()
{
	int score = 0;
	char ch, name[20];
	FILE* fp;
	printf("プレイヤーの名前:");
	scanf("%s", name);
	while (1) {
		printf("現在のスコア:%d ('e'で終了)\n", score);
		ch = getch();
		if (ch == 'e') {
			break;
		}
		score++;
	}

	//ファイル書き込み処理
	//�@ファイルのオープン
	fp = fopen("score.txt", "w");
	//�Aファイルへのnameとscoreの書き込み
	fprintf(fp, "%s\n%d\n", name, score);
	//�Bファイルのクローズ
	fclose(fp);
}
