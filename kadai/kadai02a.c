#include<stdio.h>
main()
{
	double a, b;

	printf("2�̎����l�H");
	scanf("%lf%lf", &a, &b);

	printf("*** %f �Ɓ@%f �̎l�����Z�@***\n", a, b);
	printf("�a=%f,��=%f,��=%f,��=%f\n", a + b, a - b, a * b, a / b);
}
