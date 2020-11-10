#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class Robot {
private:
	char* name;
	int hp;
	int damage;
	int defend;
	char type;
	int level;
public:
	void set(char t) {
		switch (t) {
		case 'N':
			hp = 5 * level;
			damage = 5 * level;
			defend = 5 * level; break;
		case'A':
			hp = 5 * level;
			damage = 10 * level;
			defend = 5 * level; break;
		case'D':
			hp = 5 * level;
			damage = 5 * level;
			defend = 10 * level; break;
		case'H':
			hp = 50 * level;
			damage = 5 * level;
			defend = 5 * level; break;
		}
	}
	Robot(char* n, char t, int lev) {
		name = new char[10];
		strcpy(name, n);
		type = t;
		level = lev;
		set(t);
	}
	static void transform(Robot* r, char t);
	void print() {
		cout << name << "--" << type << "--" << level << "--" << hp << "--" << damage << "--" << defend << endl;
	}
	static int count;

	~Robot() {
		delete[]name;
	}
};

int Robot::count = 0;

void Robot::transform(Robot* r, char t) {
	if (t != r->type) {
		r->type = t;
		r->set(t);
	count++;
	}
}

int main() {
	int t, l;
	char type1, type2;
	char* n = new char[10];
	cin >> t;
	while (t--) {
		cin >> n >> type1 >> l;
		cin >> type2;
		Robot robot(n, type1, l);
		Robot::transform(&robot, type2);
		robot.print();
	}
	cout << "The number of robot transform is " << Robot::count << endl;
	delete[]n;
}


/*
��Ŀ����
��дһ���������࣬���������л�������Ѫ�����˺�ֵ������ֵ�����ͺ͵ȼ�������Ѫ�����˺��ͷ����͵ȼ���������أ�
��ͨ�ͻ����ˣ�����ΪN��Ѫ�����˺��������ǵȼ���5��
�����ͻ����ˣ�����ΪA�������ǵȼ���10�����������Ժ���ͨ��һ��
�����ͻ����ˣ�����ΪD�������ǵȼ���10�����������Ժ���ͨ��һ��
�����ͻ����ˣ�����ΪH�������ǵȼ���50�����������Ժ���ͨ��һ����
�����˲�����������ӡ���������ԵĻ�ȡ�����÷��������캯�����п��ޣ�������Ҫ���б�д��
��дһ��ȫ�ֺ������ڻ����˱���ʹ�ø������ͻ������ܹ��໥ת�䡣�������������˶���ָ��ͱ����Ļ��������ͣ��������޸Ļ��������ͣ���������ص����ԡ�����������ͺͻ�����ԭ�������Ͳ�ͬ����ִ�б����ܣ�������true������������ͺ�ԭ��������ͬ����ִ�б���������false.
Ҫ���������ݳ�Ա����˽�����ԣ���C++���Ժ�����������˼�������ʵ������Ҫ��











����
��һ������t����ʾҪִ��t�λ����˱���
����ÿ���У�һ������һ�������˵����ԣ����������������͡��ȼ�����һ�������������
������������

���
ÿ����������Ļ�������Ϣ��Ҫ����û����˵Ĵ�ӡ�������������ʹ�����˲�����Ҳ���
�����������Ϊ�����ơ����͡��ȼ���Ѫ�����˺�������
���һ�����ִ�б���Ĵ���

��������
3
X001 N 5
H
X002 A 5
D
X003 D 5
D
�������
X001--H--5--250--25--25
X002--D--5--25--25--50
X003--D--5--25--25--50
The number of robot transform is 2
*/