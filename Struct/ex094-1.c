#include<stdio.h>
struct day {
	int nen;
	int tuki;
	int hi;
};

struct profile
{
	char name[20];
	struct day birth;
	char blood[5];
};
main()
{
	struct profile student[5] = {
	{ "アーサー"	,{2000,1,1},"A" },
	{ "ルシファー"	,{2001,2,2},"B" },
	{ "クシナダ"	,{2002,1,3},"AB" },
	{ "ネオ"		,{2003,1,4},"O" },
	{ "マサムネ"	,{2004,2,5},"A" }
	};

	struct profile* p;
	int i;

	p = student;

	for (i = 0; i < 5; i++) {
		if (p->birth.tuki == 2)
		{
			printf("%s--%d 年 %d 月 %d 日生まれ 血液型- %s 型\n",
				p->name, p->birth.nen, p->birth.tuki, p->birth.hi, p->blood);
		}
		p++;
	}
}
