#include<stdio.h>
main()
{
	int ia,ib;
	printf("二つの数値?");
	scanf("%d%d", &ia,&ib);
	printf("*** %d と　%d の四則演算　***",ia,ib);
	printf("%d + %d = %d\n", ia, ib,ia + ib);
	printf("%d - %d = %d\n", ia,ib,ia-ib);
	printf("%d * %d = %d\n",ia,ib,ia*ib );
	printf("%d / %d = %dあまり%d\n", ia,ib,ia/ib,ia%ib);
}
