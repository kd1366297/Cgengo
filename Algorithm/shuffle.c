#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main()
{
	int data[20];
	int i,target, w;

	//�����V���b�t��
	srand(time(0));
	//�z�����1�`20������
		for (i = 0; i < 20; i++)
		{
			data[i] = i + 1;
		}
	
	//�z������V���b�t������
	for (i = 0; i < 20; i++)
	{
		//target��0�`19�̗���������
		target = rand() % 20;

		//i�Ԗڂ�target�Ԗڂ̃f�[�^�����ւ���
		w = data[i];
		data[i] = data[target];
		data[target] = w;
	}

	//���ʕ\��
	for (i = 0; i < 20; i++)
	{
		printf("%d ", data[i]);
	}
}
