#include<stdio.h>

main()
{
	int s, i, d[] = { 18,32,53,64,85,16,7,58,37,39 };

	printf("�T���l�́H");
	scanf("%d", &s);

	for (i = 0; i < 10; i++) //i��0�`9�̊Ԃ̃��[�v
	{
		if (s == d[i])//�T���l������������
		{
			//���[�v�E�o
			break;
		}
	}

	if (i >= 10) //if (s != d[i])�ł�OK
	{
		printf("������Ȃ�����\n");
	}
	else
	{
		printf("d[%d]�ɂ�����\n", i);
	}
}
