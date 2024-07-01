#include<stdio.h>
main()
{
	int max_score, score = 0;
	char ch, max_name[20], name[20];
	FILE* fp;
	//score.txtからの読み込み処理
	//①ファイルのオープン
	fp = fopen("score.txt", "r");
	//②max_name,max_scoreの読み込み
	fscanf(fp, "%s%d", max_name, &max_score);
	//③ファイルのクローズ
	fclose(fp);
	//④画面上に最高得点者の情報を表示
	printf("最高得点 名前:%s スコア:%d\n", max_name, max_score);

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
	if (score > max_score) {
		//ファイル書き込み処理
	//①ファイルのオープン
		fp = fopen("score.txt", "w");
		//②ファイルへのnameとscoreの書き込み
		fprintf(fp, "%s\n%d\n", name, score);
		//③ファイルのクローズ
		fclose(fp);
		printf("ハイスコア更新\n");
	}
}
