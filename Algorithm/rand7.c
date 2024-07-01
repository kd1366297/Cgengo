#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int a,b,cnt=0;

	srand(time(0));
	rand();
	a = rand() % 1000 + 1;
	printf("1`1000‚Ì’†‚Å“–‚½‚è‚Ì”‚ğ—\‘z‚µ‚Ä‚­‚¾‚³‚¢\n");
	do {
		printf("“–‚½‚è‚Ì”‚ÍH->");
		scanf("%d", &b);
		if (a > b) {
			printf("“–‚½‚è‚Ì”‚æ‚è¬‚³‚¢‚Å‚·");
		}
		if (a < b) {
			printf("“–‚½‚è‚Ì”‚æ‚è‘å‚«‚¢‚Å‚·\n");
		}
		cnt++;
	} while (a != b);
	printf("³‰ğ!%d‰ñ–Ú‚Å“–‚½‚è‚Ü‚µ‚½\n", cnt);
}
