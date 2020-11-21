#include <iostream>
using namespace std;

class CVehicle {
protected:
	int max_speed;
	int speed;
	int weight;
public:
	CVehicle(){}
	CVehicle(int ms, int s, int w) {
		max_speed = ms;
		speed = s;
		weight = w;
	}
	void display() {
		cout <<"Vehicle:"<<endl<< "max_speed:" << max_speed << endl << "speed:" << speed << endl
			<< "weight:" << weight << endl;
	}
};

class CBicycle :public CVehicle {
protected:
	int height;
public:
	CBicycle(){}
	CBicycle(int ms, int s, int w, int h) {
		max_speed = ms;
		speed = s;
		weight = w;
		height = h;
	}
	void B_display() {
		cout << "Bicycle:" << endl << "max_speed:" << max_speed << endl << "speed:" << speed << endl
			<< "weight:" << weight << endl << "height:" << height << endl;
	}
};

class CMotocar : public CVehicle {
protected:
	int seat_num;
public:
	CMotocar(){}
	CMotocar(int ms, int s, int w, int sn) {
		max_speed = ms;
		speed = s;
		weight = w;
		seat_num = sn;
	}
	void M_display() {
		cout << "Motocar:" << endl << "max_speed:" << max_speed << endl << "speed:" << speed << endl
			<< "weight:" << weight << endl << "seat_num:" << seat_num << endl;
	}
};

class CMotocycle : public CBicycle, public CMotocar {
public:
	CMotocycle(int ms, int s, int w, int h, int sn) :CBicycle(ms, s, w, h), CMotocar(ms, s, w, sn) {}
	void MC_dispaly() {
		cout <<"Motocycle:"<<endl<< "max_speed:" << CBicycle::max_speed << endl << "speed:" << CBicycle::speed << endl
			<< "weight:" << CBicycle::weight << endl << "height:" << height << endl
			<< "seat_num:"<<seat_num << endl;
	}
};

int main() {
	int ms, s, w, h, sn;
	cin >> ms >> s >> w >> h >> sn;
	CVehicle v(ms, s, w);
	v.display();
	cout << endl;
	CBicycle b(ms, s, w, h);
	b.B_display();
	cout << endl;
	CMotocar m(ms, s, w, sn);
	m.M_display();
	cout << endl;
	CMotocycle mc(ms, s, w, h, sn);
	mc.MC_dispaly();
	return 0;
}



/*
��Ŀ����
1���������µ���̳нṹ��

1)һ������CVehicle��Ϊ���࣬����max_speed��speed��weight�����ݳ�Ա��display()�ȳ�Ա����

2)��CVehicle�����������г���CBicycle��������ԣ��߶�height

3)��CVehicle��������������CMotocar��������ԣ���λ��seat_num

4)��CBicycle��CMotocar������Ħ�г���CMotocycle

2���ֱ���������Ĺ��캯�����������display����������������Ҫ����

3�����������ж��������Ķ��󣬲�����֮��ͨ���������display�������������

����
��һ�У�����ٶ� �ٶ� ���� �ڶ��У��߶� �����У���λ��

���
��һ�У�Vehicle: �ڶ��м��Ժ���У���ʽ��Sample

��������
100 60 20
28
2
�������
Vehicle:
max_speed:100
speed:60
weight:20

Bicycle:
max_speed:100
speed:60
weight:20
height:28

Motocar:
max_speed:100
speed:60
weight:20
seat_num:2

Motocycle:
max_speed:100
speed:60
weight:20
height:28
seat_num:2
*/