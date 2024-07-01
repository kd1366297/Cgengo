#include<stdio.h>

#define QUEUESIZE 8
int queue[QUEUESIZE];
int head = 0;
int tail = 0;

void display(void);
int enqueue(int d);
int dequeue(int* pd);

main()
{
	int key, data, result;

	do {
		printf("\n\n◆エンキューはi、デキューはoを入力して>");
		key = getche();
		printf("\n");

		if (key == 'i') {
			printf("データ入力>");
			scanf("%d", &data);
			result = enqueue(data);
			if (result == -1) {
				printf("\n※※※キューが一杯です※※※\n");
			}
			else {
				display();
			}
		}

		if (key == 'o') {
			result = dequeue(&data);
			if (result == -1) {
				printf("\n※※※キューが空です※※※\n");
			}
			else {
				printf("キューからデータ(%d)を取り出しました\n", data);
				display();
			}
		}
	} while (key != 'e');
}

void display(void)
{
	int i;

	printf("\n===現在のキューの内容===\n");
	for (i = 0; i < QUEUESIZE; i++) {
		printf("queue[%2d]は%5d", i, queue[i]);
		if (i == head) {
			printf("←headが示している所(現在headは%d)", head);
		}
		if (i == tail) {
			printf("←tailが示している所(現在tailは%d)", tail);
		}
		printf("\n");
	}
	return;
}

int enqueue(int d)
{
	if((tail + 1) % QUEUESIZE == head) { return -1; }
	queue[tail] = d;
	tail++;
	tail = tail % QUEUESIZE;
	return 0;
}

int dequeue(int* pd)
{
	if (tail == head) { return-1; }
	*pd = queue[head];
	queue[head] = 0;
	head++;
	head = head % QUEUESIZE;
	return 0;
}
