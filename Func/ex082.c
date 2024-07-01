#include<stdio.h>
#include<string.h>
void sort(int* array, int size, int order);

main()
{
	int data[8] = { 6,10,8,2,9,5,1,7 };
	int i;
	char str[256];
	printf("ソート方向を入力:");
	gets(str);
	if (strcmp(str, "昇順") == 0)
	{
		sort(data, 8, 0);
	}
	else {
		printf("ソート方向は、昇順か降順で入力してください\n");
		return 1;
	}
	for (i = 0; i < 8; i++) {
		printf("%d", data[i]);
	}
	return 0;
}

void sort(int* array, int size, int order)
{
	int i, j, w;
	switch (order) {
	case 0:
		for (i = 0; i < size - 1; i++) {
			for (j = i + 1; j < size; j++) {
				if ((*array + i) > * (array + j)) {
					w = *(array + i);
					*(array + i) = *(array + j);
					*(array + j) = w;
				}
			}
		}

		break;
	case 1:
		for (i = 0; i < size - 1; i++) {
			for (j = i + 1; j < size; j++) {
				if ((*array + i) > * (array + j)){
					w = *(array + i);
					*(array + i) = *(array + j);
					*(array + j) = w;
				}
			}
		}
		break;
	}
}
