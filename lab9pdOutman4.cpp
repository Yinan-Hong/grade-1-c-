//���˻�ûѧ�ģ���=.=

#include <iostream>
using namespace std;

class Outman {
protected:
	int hp; int rank; int damage; int exp; int money;
public:
	friend class Boss;
	Outman() {}
	Outman(int r) :rank(r) {
		hp = 10 * rank;
		damage = 3 * rank;
		money = 10 * rank;
		exp = 0;
	}
	void excape() {
			money = 0;
			cout << "lose" << endl;
	}
	void attacked(int d) { hp -= d / 2; }
	void restore() {
		if (hp < rank * 10 / 2 && hp>10)
			while (money > 0)
				if (hp < rank * 10) {
					hp++;
					money -= 10;
				}
	}
	void win(int e, int m) {
		exp += e;
		money += m;
	}
	void upgrade() {
		while (exp >= rank * 10) {
			exp -= rank * 10;
			rank++;
			hp = rank * 10;
			damage = rank * 3;
		}
	}
	void display() {
		cout << "������״̬(" << "rank=" << rank << " hp=" << hp << " damage=" <<
			damage << " exp=" << exp << " money=" << money << ")" << endl;
	}
	int gethp() { return hp; }
	int getrank() { return rank; }
	int getdamage() { return damage; }
	int getexp() { return exp; }
	int getmoney() { return money; }
};

class Monster :public Outman {
public:
	Monster(){}
	Monster(int r){
		rank = r;
		hp = 20 * rank;
		damage = 2 * rank;
		money = 10 * rank;
		exp = 10 * rank;
	}
	virtual void attacked(int d) {
		hp -= d;
	}
	void next(int r) {
		rank = r;
		hp = 20 * rank;
		damage = 2 * rank;
		money = 10 * rank;
		exp = 10 * rank;
	}
};

class Boss :public Monster {
private:
	int count;
public:
	Boss() {rank = 10;hp = 300;exp = 1000;damage = 50;money = 1001;count = 0;}
	void XP(Outman& o) {
		count = 0;
		o.attacked(damage * 3);
	}
	void attack(Outman& o) {
		if (count == 4)
			XP(o);
		else {
			o.attacked(damage);
			count++;
		}
	}
};

int main() {
	int t, r, n, k;
	cin >> t;
	while (t--) {
		cin >> r;
		Outman outman(r);
		cin >> n >> k;
		Monster monster(k);
		outman.display();
		//monster.display();

		bool flag = true;
		while (n--) {
			while (1) {
				monster.attacked(outman.getdamage());//outman attack
				if (monster.gethp() > 0) {
					outman.attacked(monster.getdamage());//monster fightback
					if (outman.gethp() < 10) {
						outman.excape();
						flag = false;
						break;
					}
					else 
						outman.restore();
				}
				else {
					cout << "win" << endl;
					outman.win(monster.getexp(), monster.getmoney());
					outman.upgrade();
					break;
				}
			}
			if (!flag) {
				outman.display();
				break;
			}
			monster.next(k);
		}
		if (flag) {
			outman.display();
			Boss boss;
			while (1) {
				boss.attacked(outman.getdamage());//outman attack
				if (boss.gethp() > 0) {
					boss.attack(outman);
					if (outman.gethp() < 10) {
						outman.excape();
						flag = false;
						break;
					}
					else
						outman.restore();
				}
				else {
					cout << "win Boss" << endl;
					outman.win(boss.getexp(), boss.getmoney());
					outman.upgrade();
					break;
				}
			}
			outman.display();
		}
	}
	return 0;
}

/*
��Ŀ����
������֯���޸�ǰ�桰���ʵ�֡��Ĵ��룬���ü̳�ʵ���������ݡ�

������������С���޹��еĹ����У����������Լ��ĵȼ�����һ�о�����ʱ�򣬾Ϳ�����սС���޵�ͷBoss�ˡ����Boss�Ϳ��Ի�����յ�ʤ����

�ڹ�����Ļ����ϣ������ʵ��һ������Boss�ࡣ���б�Ҫ����԰������͹�����������Ӧ���޸ġ�

Boss��Թ����������������޸ģ�

l  Boss���Եĳ�ʼֵ��һ����޲�ͬ���ȼ�Ϊ10������ֵΪ300������ֵ��1000����������50��Ǯ����1001��

l  Boss��һ���µķ�����������(XP)���÷�������������������3�Ρ�

l  Boss�ķ�������(fightback)Ҳ��һ����޲�ͬ��һ��������ܵ��������Ĺ����ͻᷴ��һ�Σ���ÿ��Boss�ܵ������������Ĵ���(count)�ۼ�5�Σ��ͻ�ʹ�þ���(XP)��



*******************************************************************************

Outman��������������ڴ�����е�С���޺󣬽���ս����֮����

����main������ʵ�����¼ܹ�

int main(){

	//������Դ���



	while(t--){

//����������ĵȼ�ֵ�����õȼ�ֵ������һ��������������ʾ�����������ʼ״̬��

//������޸����͵ȼ�



	while(��������)//ֻҪ������û��Ҳû���ܣ��ͼ�����n�����޵�ս��

	{

		 ���ù��޵ȼ�ֵ���ɹ��޶���



		 //����ս����־flagΪtrue������ս��ѭ�����������£�

		 while(flag) //��ս��δ�����ͼ���

		 {

			 //����������1��

			 if (��������)  //����û��

			 {   //���޷���1��



				  if (������)       //������û��Ҳ������

					  //��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ



				  else

				  {   //���������ܣ������"lose"���س�



					  //���������״̬������display����



					  //����flagΪfalse��ֹͣս��



				  }

			 }

			 else //��������

			 {

				  //������ʤ���������"win"���س�



				  //����������



				  //����flagΪfalse��ֹͣս��



			 }

		 }

	}



	if(��������)//�������n��С���ް�������û��Ҳû���ܣ�����սBoss

	{

		 //�����������ǰ״̬



		 //����Boss�����ʼ��





		 //����ս����־flagΪtrue������ս��ѭ�����������£�



		 while(flag) //��ս��δ�����ͼ���

		 {

			 //����������1��



			 if (��������)  //Bossû��

			 {   //Boss����1��



				  if (������)       //������û��Ҳ������

					  //��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ



				  else

				  {   //���������ܣ������"lose"���س�



					  //���������״̬������display����



					  //����flagΪfalse��ֹͣս��



				  }

			 }



			 else //��������

			 {

				  //������ʤ���������"win Boss"���س�



				  //����������



				  //���������״̬������display����



				  //����flagΪfalse��ֹͣս��



			 }

		 }

	}

	}

	return 0;

}


����
��1������t��ʾ��t������ʵ��

����ÿ������ʵ��������������������ȼ�

������һ������n��k����ʾ���������͵ȼ�

���
 ���ÿ������ʵ����ս�������

����ÿһ��ʵ����������£�

��һ�а�������״̬

�ڶ���~��n+1�����������������ÿ�����޵Ľ����

�����������n�����޶�����ˣ�

	 ��n+2�������ʱ��������״̬

	 ��n+3��������������������Ľ��

	 ��n+4����������������������״̬



�����������ĳ�����޴�ܣ������ս���������һ�����ս�����������״̬������������������ս����

��������
2
5
5 5
20
5 10
�������
������״̬(rank=5 hp=50 damage=15 exp=0 money=50)
win
win
win
win
win
������״̬(rank=8 hp=60 damage=24 exp=70 money=150)
lose
������״̬(rank=8 hp=0 damage=24 exp=70 money=0)
������״̬(rank=20 hp=200 damage=60 exp=0 money=200)
win
win
win
win
win
������״̬(rank=22 hp=220 damage=66 exp=90 money=700)
win Boss
������״̬(rank=26 hp=260 damage=78 exp=150 money=1701)
*/