#include<stdio.h>
main()
{
	FILE* fp;
	int lv, hp;
	char c, str[256], equip[100];
	fp = fopen("file02.txt", "r");
	fscanf(fp, "%s", str);
	printf("‘•”õ1:%s\n", str);
	fscanf(fp, "%s", str);
	printf("‘•”õ2:%s\n", str);
	fscanf(fp, "%s", str);
	printf("‘•”õ3:%s\n", str);
	//
	fscanf(fp, "%d%d%s", &lv, &hp, equip);
	printf("lv:%d hp:%d ‘•”õ:%s\n", lv, hp, equip);
	//fgets‚Ì—á
	c = fgetc(fp); //‰üs‚Ì‚İ“Ç‚İæ‚è
	fgets(str, sizeof(str), fp);
	printf("%s\n", str);
	fclose(fp);
}
