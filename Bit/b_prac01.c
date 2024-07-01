#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Skil_Num 3
#define Mob_Num 3
//符号なし整数をUINTで再定義
typedef usingned int UINT;

typedef struct {
	char name[20];
	int type;
	int use_mp;
	int effect;
}Skill;
typedef struct {
	char name[20];
	int hp;
	int stk;
	int def;
	UINT state;
}Spec;
typedef struct {
	Spec sp;
	int maxhp;
	int mp;
	Skill skl[Skil_Num];
}Chara;
typedef struct {
	Spec sp;
	int rate;
}Mob;

enum BitState
{
	Base = 0,			//00000000 通常状態
	Poison = 1 << 0,	//00000001 毒状態
	Sleep = 1 << 1,		//00000010 眠り状態
	Paralysis = 1 << 2,	//00000100 麻痺状態
	Burn = 1 << 3,		//00001000 やけど状態
	AtkUp = 1 << 4,		//00010000 攻撃力アップ状態
	AtkDown = 1 << 5,	//00100000 攻撃力ダウン状態
	Dead = 1 << 6,		//0000 0000 0100 0000(死亡フラグ)
	Atk_Skill = 1 << 7	//0000 0000 1000 0000
						//(このフラグがONのキャラしか状態異常を付加できない)
};

int TurnCount = 0;	//経過ターン(0～999)

void DisplayStatus(Chara c);
//void ChangeFlag(UINT* s);
//void ClearFlag(UINT* s);

//戦闘モードへ移行す関数
void BattleMode(Chara* c, Mob m);
//戦闘時のメニュー表示
int DisplayMenu(void);
//スキル使用時のメニュー表示
int SkillMenu(Chara c);
//攻撃側と防御側のパラメータを使った攻撃ダメージ計算
int DamageCalc(Spec sp1, Spec sp2);
//戦闘モード時のHP計算と死亡判定
void BattleMessage(Spec sp1, Spec* sp2);



main(int argc,char *argv[])
{
	//乱数列(シード)の初期化
	srand(time(0));

	//			name	  hp   atk def state maxhp mp
	Chara chara = { "主人公",2000,200,100,Base,2000,150,
		//	sk.name
			{{"HP回復",		0,	50,	800},
			{"攻撃力アップ",1,	50,	120},
			{"状態異常回復",2,	20,	0}} };
	Mob mob[Mob_Num] = {
		//name hp  atk def state              rate%
		{"敵A",700,150,800,Poison | Atk_Skill,30},
		{"敵B",1500,200,200,Burn | Atk_Skill,30},
		{"ボス",5000,200,80,AtkDown | Atk_Skill,10} };

	//乱数で0～Mob_Num-1の数値を求める
	int num = rand() % Mob_Num;
	//実行時にコマンドライン引数があった場合
	if (argc > 1) {
		//引数を数値に変換
		num = atoi(argv[1]);
		//因数の数値が0～Mob_Num-1の範囲になければ
		if (num < 0 || num >= Mob_Num) {
			//乱数を生成
			num = rand() % Mob_Num;
		}
	}
	//戦闘モードを開始
	BattleMode(&chara, mob[num]);
	if (chara.sp.state & Dead) {
		printf("%sの死亡によりゲームオーバー\n", chara.sp.name);
	}
}

void DisplayStatus(UINT s)
{
	printf("****現在の状態****\n");
	if (s & Poison)
	{
		printf("毒\n");
	}
	if (s & Sleep)
	{
		printf("睡眠\n");
	}
	if (s & Paralysis)
	{
		printf("麻痺\n");
	}
	if (s & Burn)
	{
		printf("やけど\n");
	}
	if (s & AtkUp)
	{
		printf("攻撃力アップ\n");
	}
	if (s & AtkDown)
	{
		printf("攻撃力ダウン\n");
	}
	if (s == Base)
	{
		printf("通常状態\n");
	}
	printf("******************\n");
}
void ChangeFlag(UINT* s)
{
	int a;
	while (1){
		printf("どの状態にしますか?\n");
		printf("1:毒 2:睡眠 3:麻痺 4:火傷 5:攻撃↑6:攻撃↓0:終了>");
		scanf("%d", &a);
		if (a == 0) {
			break;
		}
		switch (a) {
		case 1:
			*s |= Poison;
			break;
		case 2:
			*s |= Sleep;
			break;
		case 3:
			*s |= Paralysis;
			break;
		case 4:
			*s |= Burn;
			break;
		case 5:
			*s |= AtkUp;
			break;
		case 6:
			*s |= AtkDown;
			break;
		default:	//1～6に合致しなかったときの処理
			break;
		}
	}
}
void ClearFlag(UINT* s)
{
	int a;
	while (1) {
		printf("どの状態を解除しますか\n");
		printf("1:毒 2:睡眠 3:麻痺 4:火傷 5:攻撃↑6:攻撃↓0:終了>");
		scanf("%d", &a);
		if (a == 0) {
			break;
		}
		switch (a) {
		case 1:
			*s &= ~Poison;
			break;
		case 2:
			*s &= ~Sleep;
			break;
		case 3:
			*s &= ~Paralysis;
			break;
		case 4:
			*s &= ~Burn;
			break;
		case 5:
			*s &= ~AtkUp;
			break;
		case 6:
			*s &= ~AtkDown;
			break;
		default:
			break;
		}
	}
}
	