
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Skil_Num 4	//スキル数
#define Mob_Num 3	//敵の種類
//符号無し整数をUINTで再定義
typedef unsigned int UINT;

typedef struct { //Skill型構造体
	char name[20]; //スキル名
	int type;      //スキルの種類（0: HP回復, 1: AtkUp, 2: 状態異常回復）
	int use_mp;    //使用MP量
	int effect;    //スキル効果
} Skill;
typedef struct { //Spec型構造体
	char name[20]; //名前
	int hp;        //HP
	int atk;       //攻撃力
	int def;       //防御力
	UINT state;    //状態
} Spec;
typedef struct { //Chara型構造体
	Spec sp;       //Spec型構造体変数
	int maxhp;     //最大HP
	int mp;        //MP
	Skill skl[Skil_Num]; //Skill型構造体配列
} Chara;
typedef struct { //Mob型構造体
	Spec sp;       //Spec型構造体変数
	int rate;      //状態異常攻撃発生レート%表記
} Mob;

//列挙型BitStateの宣言
enum BitState
{
	//通常状態
	Base = 0,            //0000 0000 0000 0000
	//(1からいくつ左にシフトするか)
	Poison = 1 << 0,     //0000 0000 0000 0001(毒)
	Sleep = 1 << 1,      //0000 0000 0000 0010(睡眠)
	Paralysis = 1 << 2,  //0000 0000 0000 0100(麻痺)
	Burn = 1 << 3,       //0000 0000 0000 1000(火傷)
	AtkUp = 1 << 4,      //0000 0000 0001 0000(攻撃力Up)
	AtkDown = 1 << 5,    //0000 0000 0010 0000(攻撃力Down)
	Dead = 1 << 6,       //0000 0000 0100 0000(死亡フラグ)
	Atk_Skill = 1 << 7,  //0000 0000 1000 0000
						 //(このフラグがONのキャラしか状態異常を付加できない）
	DefUp = 1 << 8		 //0000 0001 0000 0000(防御力アップ)
};

int TurnCount = 0;     //経過ターン(0〜999)


//状態を表示する関数
void DisplayStatus(Chara c);

//戦闘モードへ移行する関数
void BattleMode(Chara* c, Mob m);
//戦闘時のメニュー表示を行う
int DisplayMenu(void);
//スキル使用時のメニュー表示を行う
int SkillMenu(Chara c);
//攻撃側と防御側のパラメータを使った攻撃ダメージ計算
int DamageCalc(Spec sp1, Spec sp2);
//戦闘モード時のHP計算と死亡判定
void BattleMessage(Spec sp1, Spec* sp2);

/* b_prac01.exe [数字:0~Mob_Num-1]
* [数字:0~Mob_Num-1]は0からMob_Num-1までの数字を指定して実行することで
* 登場する敵の種類を指定できる。省略した場合は0~Mob_Num-1の乱数となる */
main(int argc, char* argv[])
{
	//乱数列（シード）の初期化
	srand(time(0));
	//自キャラと敵キャラのパラメータ設定
	//未実装項目：データファイルからの読み込み
	//              name    hp    atk  def  state maxhp mp
	Chara chara = { "主人公",2000, 200, 100, Base, 2000, 150,
		//  sk.name    type usemp effect 
		   {{"HP回復",		0,   50,  800},
			{"攻撃力アップ",1,   50,  120},
			{"防御力アップ",3,	 50,  150},
			{"状態異常回復",2,   20,    0}} };
	Mob mob[Mob_Num] = {
		//name hp   atk def  state               rate%
		{"敵A", 700,150, 800,Poison | Atk_Skill,  30},
		{"敵B",1500,200, 200,Burn | Atk_Skill,  30},
		{"ボス",5000,200, 80,AtkDown | Atk_Skill, 10} };

	//乱数で0~Mob_Num-1の数値を求める
	int num = rand() % Mob_Num;
	//実行時にコマンドライン引数があった場合
	if (argc > 1) {
		//引数を数値に変換
		num = atoi(argv[1]);
		//引数の数値が0~Mob_Num-1の範囲になければ
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
/*int DamageCalc(Spec sp1, Spec sp2)
* 与ダメ計算関数
* 第1引数：Spec型構造体変数（攻撃側）
* 第2引数：Spec型構造体変数（防御側）
* （与ダメ）＝攻撃側Atk×(攻撃側Atk÷防御側Def）＋攻撃側Atk×乱数0~0.5
*/
int DamageCalc(Spec sp1, Spec sp2) {
	int damage;
	//攻撃力ダウンフラグがONで、Atk_SkillがOFFのとき（主人公のみこの条件に該当）
	if ((sp1.state & AtkDown) && !(sp1.state & Atk_Skill)) {
		//攻撃力を0.8倍にしてダメージ計算
		sp1.atk *= 0.8;
	}
	damage = sp1.atk * ((float)sp1.atk / sp2.def)
		+ sp1.atk * (rand() % 50) / 100.0;
	//100分の1の確率で会心/痛恨の一撃
	if (rand() % 100 <= 50) {
		return 2 * damage;  //ダメージ量2倍
	}
	return damage;  //通常ダメージ
}
/*void BattleMessage(Spec sp1, Spec* sp2)
* 戦闘モード時のメッセージ表示を行う
* 第1引数：Spec型構造体変数（攻撃側）
* 第2引数：Spec型構造体変数のアドレス（防御側）
*/
void BattleMessage(Spec sp1, Spec* sp2) {
	int damage;
	TurnCount++;
	printf("%sの攻撃\n", sp1.name);
	damage = DamageCalc(sp1, *sp2);
	printf("%sに%dのダメージ\n\n", sp2->name, damage);
	sp2->hp -= damage;
	if (sp2->hp <= 0) {
		printf("%sは倒された\n", sp2->name);
		sp2->state |= Dead;
	}
}
/*void BattleMode(Chara* c, Mob m)
* 戦闘モード時のメッセージ表示を行う
* 第1引数：Chara型構造体変数のアドレス（自キャラ）
* 第2引数：Mob型構造体変数（敵キャラ）
*/
void BattleMode(Chara* c, Mob m) {
	int command, skill;
	system("cls");      //コマンドプロンプトのcls命令の実行
	DisplayStatus(*c);
	printf("%sがあらわれた！\n", m.sp.name);
	while (1) {
		command = DisplayMenu();
		if (c->sp.state & Poison) {
			c->sp.hp *= 0.8;
		}
		if (c->sp.state & Burn) {
			c->sp.hp *= 0.9;
			c->mp *= 0.9;
		}
		//[たたかう]
		if (command == 1) {
			DisplayStatus(*c);
			//TurnCountが偶数のときは自キャラの攻撃
			if (TurnCount % 2 == 0) {
				BattleMessage(c->sp, &m.sp);
				//敵キャラの死亡フラグがONなら
				if (m.sp.state & Dead) {
					break;
				}
			}
			//TurnCountが奇数のときは敵の攻撃
			if (TurnCount % 2 == 1) {
				BattleMessage(m.sp, &c->sp);
				//状態異常付加確率の計算
				if (rand() % 100 < m.rate) {
					printf("状態異常攻撃を受けた！\n");
					//主人公に状態異常を付加するときには、Atk_Skillフラグを除去しておく
					c->sp.state |= (m.sp.state & ~Atk_Skill);
				}
				//自キャラの死亡フラグがONなら
				if (c->sp.state & Dead) {
					break;
				}
				else {
					DisplayStatus(*c);
				}
			}
			else if (command == -1) {
				c->sp.state |= Dead;
				return;
			}
		}
		//[スキル]
		else if (command == 2) {
			printf("スキルの選択\n");
			skill = SkillMenu(*c);//skillは0〜20のいずれか
			//MP残量チェック
			if (c->mp >= c->skl[skill].use_mp){
				switch (c->skl[skill].type) {
				case 0:	//HP回復スキル使用時の処理
					c->sp.hp += c->skl[skill].effect;
					if (c->sp.hp > c->maxhp) { c->sp.hp = c->maxhp; }
					//自キャラのMPを使用した分減らす
					c->mp -= c->skl[skill].use_mp;
					printf("HPを%d回復した!\n", c->skl[skill].effect);
					DisplayStatus(*c);
					break;
				case 1:	//攻撃力アップの処理
					//自キャラATKを1.20倍(=120÷100)
					c->sp.atk *= c->skl[skill].effect / 100.0;
					//自キャラのMPを使用した分減らす
					c->mp -= c->skl[skill].use_mp;
					//攻撃力アップフラグON
					c->sp.state |= AtkUp;
					printf("攻撃力がアップした!\n");
					DisplayStatus(*c);
					break;
				case 2:	//状態異常回復の処理
					UINT back = Base;
					if (c->sp.state & AtkUp) {
						back |= AtkUp;
					}
					if (c->sp.state & DefUp) {
						back |= DefUp;
					}
					c->sp.state = Base;
					c->sp.state |= back;

					//攻撃力アップは異常ではないので残す
					if (c->sp.state & AtkUp) {
						c->sp.state = Base;	//状態変化をリセット
						c->sp.state |= AtkUp;	//攻撃力アップを再度付加
					}
					else {
						c->sp.state = Base;	//状態変化をリセット
					}
					//自キャラのMPを使用した分減らす
					c->mp -= c->skl[skill].use_mp;
					printf("状態異常が回復した!\n");
					DisplayStatus(*c);
					break;
				case 3:	//防御力アップ処理
					//自キャラのDef値を1.5倍にする
					c->sp.def *= c->skl[skill].effect / 100.0;
					//自キャラのDefUpフラグを立てる
					c->sp.state |= DefUp;
					//自キャラのMPを使用した分減らす
					c->mp -= c->skl[skill].use_mp;
					//メッセージで防御力がアップしたことを表示
					printf("防御力がアップした!\n");
					//自キャラのステータスを表示
					DisplayStatus(*c);
					break;

				default:
					break;
				}
			}
			else {	//MP残量チェックにひっかかった時の処理
				printf("MPが足りない!\n");
			}
		}
	}
}


/*void DisplayStatus(Chara c)
* 戦闘モード時の自キャラのステータス表示
* 第1引数：Chara型構造体変数（自キャラ）*/
void DisplayStatus(Chara c) {
	printf("******************\n");
	//HPとMP表示
	printf("HP:%-4d  MP:%-3d\n", c.sp.hp, c.mp);
	//フラグが立っているビットの確認
	if (c.sp.state) {
		printf("状態： ");
		if (c.sp.state & Poison) { printf("毒 "); }
		if (c.sp.state & Sleep) { printf("睡眠 "); }
		if (c.sp.state & Paralysis) { printf("麻痺 "); }
		if (c.sp.state & Burn) { printf("火傷 "); }
		if (c.sp.state & AtkUp) { printf("攻撃力アップ "); }
		if (c.sp.state & AtkDown) { printf("攻撃力ダウン"); }
		if (c.sp.state & DefUp) { printf("防御力アップ"); }
	}
	printf("\n******************\n");
}

int DisplayMenu(void)
{
	char ch;
	while (1)
	{
		printf("--------\nコマンド選択\n");
		printf("1.戦う2.スキル3.防御\n\n");
		ch = getch();
		if (ch > '0' && ch < '4')
		{
			return ch - '0';
		}
		else if (ch == 'q')
		{
			//隠しコマンド:強制終了'q'
			return-1;
		}
	}
}

int SkillMenu(Chara c) {
	int i,ch;
	while (1) {
		printf("----------\nスキルを選択\n");
		for (i = 0; i < Skil_Num; i++) {
			printf("%d.%s\n", i + 1, c.skl[i].name);
		}
		printf("\n");
		ch = getch() - '0';
		if (ch > 0 && ch <= Skil_Num) {
			return ch - 1;
		}
	}
}