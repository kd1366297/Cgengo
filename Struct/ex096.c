#include<stdio.h>
struct syohin_data {
	char name[20];
	int tanka;
};

void display3(struct syohin_data* syohin);

main()
{
	struct syohin_data syohin = { "ƒPƒVƒSƒ€",50 };

	display3(&syohin);
}

void display3(struct syohin_data *syohin)
{
	printf("%s %d\n", syohin->name, syohin->tanka);
}
