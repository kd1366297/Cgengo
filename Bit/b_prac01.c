#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Skil_Num 3
#define Mob_Num 3
//�����Ȃ�������UINT�ōĒ�`
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
	Base = 0,			//00000000 �ʏ���
	Poison = 1 << 0,	//00000001 �ŏ��
	Sleep = 1 << 1,		//00000010 ������
	Paralysis = 1 << 2,	//00000100 ��჏��
	Burn = 1 << 3,		//00001000 �₯�Ǐ��
	AtkUp = 1 << 4,		//00010000 �U���̓A�b�v���
	AtkDown = 1 << 5,	//00100000 �U���̓_�E�����
	Dead = 1 << 6,		//0000 0000 0100 0000(���S�t���O)
	Atk_Skill = 1 << 7	//0000 0000 1000 0000
						//(���̃t���O��ON�̃L����������Ԉُ��t���ł��Ȃ�)
};

int TurnCount = 0;	//�o�߃^�[��(0�`999)

void DisplayStatus(Chara c);
//void ChangeFlag(UINT* s);
//void ClearFlag(UINT* s);

//�퓬���[�h�ֈڍs���֐�
void BattleMode(Chara* c, Mob m);
//�퓬���̃��j���[�\��
int DisplayMenu(void);
//�X�L���g�p���̃��j���[�\��
int SkillMenu(Chara c);
//�U�����Ɩh�䑤�̃p�����[�^���g�����U���_���[�W�v�Z
int DamageCalc(Spec sp1, Spec sp2);
//�퓬���[�h����HP�v�Z�Ǝ��S����
void BattleMessage(Spec sp1, Spec* sp2);



main(int argc,char *argv[])
{
	//������(�V�[�h)�̏�����
	srand(time(0));

	//			name	  hp   atk def state maxhp mp
	Chara chara = { "��l��",2000,200,100,Base,2000,150,
		//	sk.name
			{{"HP��",		0,	50,	800},
			{"�U���̓A�b�v",1,	50,	120},
			{"��Ԉُ��",2,	20,	0}} };
	Mob mob[Mob_Num] = {
		//name hp  atk def state              rate%
		{"�GA",700,150,800,Poison | Atk_Skill,30},
		{"�GB",1500,200,200,Burn | Atk_Skill,30},
		{"�{�X",5000,200,80,AtkDown | Atk_Skill,10} };

	//������0�`Mob_Num-1�̐��l�����߂�
	int num = rand() % Mob_Num;
	//���s���ɃR�}���h���C���������������ꍇ
	if (argc > 1) {
		//�����𐔒l�ɕϊ�
		num = atoi(argv[1]);
		//�����̐��l��0�`Mob_Num-1�͈̔͂ɂȂ����
		if (num < 0 || num >= Mob_Num) {
			//�����𐶐�
			num = rand() % Mob_Num;
		}
	}
	//�퓬���[�h���J�n
	BattleMode(&chara, mob[num]);
	if (chara.sp.state & Dead) {
		printf("%s�̎��S�ɂ��Q�[���I�[�o�[\n", chara.sp.name);
	}
}

void DisplayStatus(UINT s)
{
	printf("****���݂̏��****\n");
	if (s & Poison)
	{
		printf("��\n");
	}
	if (s & Sleep)
	{
		printf("����\n");
	}
	if (s & Paralysis)
	{
		printf("���\n");
	}
	if (s & Burn)
	{
		printf("�₯��\n");
	}
	if (s & AtkUp)
	{
		printf("�U���̓A�b�v\n");
	}
	if (s & AtkDown)
	{
		printf("�U���̓_�E��\n");
	}
	if (s == Base)
	{
		printf("�ʏ���\n");
	}
	printf("******************\n");
}
void ChangeFlag(UINT* s)
{
	int a;
	while (1){
		printf("�ǂ̏�Ԃɂ��܂���?\n");
		printf("1:�� 2:���� 3:��� 4:�Ώ� 5:�U����6:�U����0:�I��>");
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
		default:	//1�`6�ɍ��v���Ȃ������Ƃ��̏���
			break;
		}
	}
}
void ClearFlag(UINT* s)
{
	int a;
	while (1) {
		printf("�ǂ̏�Ԃ��������܂���\n");
		printf("1:�� 2:���� 3:��� 4:�Ώ� 5:�U����6:�U����0:�I��>");
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
	