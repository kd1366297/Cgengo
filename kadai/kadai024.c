#include<stdio.h>
main()
{
	int ia,ib;
	printf("��̐��l?");
	scanf("%d%d", &ia,&ib);
	printf("*** %d �Ɓ@%d �̎l�����Z�@***",ia,ib);
	printf("%d + %d = %d\n", ia, ib,ia + ib);
	printf("%d - %d = %d\n", ia,ib,ia-ib);
	printf("%d * %d = %d\n",ia,ib,ia*ib );
	printf("%d / %d = %d���܂�%d\n", ia,ib,ia/ib,ia%ib);
}
