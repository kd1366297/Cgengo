#include<stdio.h>
main()
{
	int d[] = {30,7,25,16,10};
	int i, j, w;

	printf("�\�[�g�O\n");
	for (i = 4; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (d[j] > d[j + 1])
			{
				//����ւ�
				w = d[j];
				d[j] = d[j + 1];
				d[j + 1] = w;
			}
		}
	}

	//���ʕ\��
	for (i = 0; i < 5; i++) {
		printf("d[%d]:%d\n", i, d[i]);
	}
}
