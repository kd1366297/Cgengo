#include<stdio.h>
main()
{
	int d[] = {30,7,25,16,10};
	int i, j, w;

	printf("ソート前\n");
	for (i = 0; i < 4; i++) //比較元
	{
		for (j=i+1;j<5;j++) //比較先
		{
			if (d[i]>d[j])
			{
				//入れ替え
				w = d[i];
				d[i] = d[j];
				d[j] = w;
			}
		}
	}

	//結果表示
	for (i = 0; i < 5; i++) {
		printf("d[%d]:%d\n", i, d[i]);
	}
}
