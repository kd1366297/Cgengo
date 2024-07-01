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
	strcpy(fdat.name, "peach");
	fdat.price = 300;
	fdat.point = 5;
	fdat.number = 3;
	fdat.total = fdat.price * fdat.number;
	printf("¤•i–¼:=%s\n",fdat.name);
	printf("‰¿Ši:%d‰~\n", fdat.price);
	printf("‚¨‘E‚ß“x:");
	for (int i = 0; i < fdat.point; i++) {
		printf("š");
	}
	printf("\nŒÂ”:%dŒÂ\n", fdat.number);
	printf("‹àŠz:\\%d-\n", fdat.total);
}
