#include<stdio.h>
int GetMax(int* array, int size);
int GetMin(int* array, int size);

main()
{
	int data[8] = { 6,10,8,2,9,5,1,7 };
	printf("Å‘å’l=%d\n", GetMax(data, 8));
	printf("Å¬’l=%d\n", GetMin(data, 8));
}

int GetMax(int* array, int size)
{
	int max, i;
	for (max = *array, i = 1; i < size; i++)
	{
		if (max < *(array + i))
		{
			max = *(array + i);
		}
	}
	return max;
}

int GetMin(int* array, int size)
{
	int min, i;
	for (min = *array, i = 1; i < size; i++)
	{
		if (min > *(array + i))
		{
			min = *(array + i);
		}
	}
	return min;
}
