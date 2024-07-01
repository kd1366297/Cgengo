#include<stdio.h>
main()
{
	char data[] = "Apple";
	int i;

	printf("ˆê•¶Žš‚¸‚Â•\Ž¦\n");
	i = 0;
	while (data[i] != '\0') {
		printf("%c", data[i]);
		i++;
	}
	printf("\n•¶Žš—ñ‚Å•\Ž¦\n");
	printf("%s\n", &data[0]);
}
