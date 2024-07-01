#include<stdio.h>
main()
{
	double a, b;

	printf("2つの実数値？");
	scanf("%lf%lf", &a, &b);

	printf("*** %f と　%f の四則演算　***\n", a, b);
	printf("和=%f,差=%f,積=%f,商=%f\n", a + b, a - b, a * b, a / b);
}
