#include<stdio.h>
#include<string.h>
struct fruit {
	char name[30];
	int price;
	int point;
	int number;
	int total;
};
main()
{
	struct fruit fdat;
	struct fruit* p;
	p = &fdat;
	strcpy(p->name, "peach");
	p->price = 300;
	p->point = 5;
	p->number = 3;
	p->total = p->price * p->number;

	printf("���i��:=%s\n", p->name);
	printf("���i:%d�~\n", p->price);
	printf("���E�ߓx:");
    printf("5�|�C���g");
	printf("\n��:%d��\n", p->number);
	printf("���z:\\%d-\n", p->total);
}
