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

	printf("¤•i–¼:=%s\n", p->name);
	printf("‰¿Ši:%d‰~\n", p->price);
	printf("‚¨‘E‚ß“x:");
    printf("5ƒ|ƒCƒ“ƒg");
	printf("\nŒÂ”:%dŒÂ\n", p->number);
	printf("‹àŠz:\\%d-\n", p->total);
}
