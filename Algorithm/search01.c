#include<stdio.h>

main()
{
	int s, i, d[] = { 18,32,53,64,85,16,7,58,37,39 };

	printf("探索値は？");
	scanf("%d", &s);

	for (i = 0; i < 10; i++) //iが0～9の間のループ
	{
		if (s == d[i])//探索値が見つかったか
		{
			//ループ脱出
			break;
		}
	}

	if (i >= 10) //if (s != d[i])でもOK
	{
		printf("見つからなかった\n");
	}
	else
	{
		printf("d[%d]にあった\n", i);
	}
}
