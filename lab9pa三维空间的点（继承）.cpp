#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

class C2D {
protected:
	float x;
	float y;
public:
	C2D() {}
	C2D(float X, float Y) {
		x = X;
		y = Y;
	}
	
	double getDistance() {
		return sqrt(x * x + y * y );
	}
};

class C3D :public C2D {
protected:
	float z;
public:
	C3D(float X, float Y, float Z) {
		x = X;
		y = Y;
		z = Z;
	}
	double getDistance3() {
		return sqrt(x * x + y * y + z * z);
	}
};

int main() {
	float x, y, z;
	cin >> x >> y;
	C2D point1(x, y);
	cout << point1.getDistance() << endl;
	cin >> x >> y >> z;
	C3D point2(x, y, z);
	cout << point2.getDistance3() << endl;
	cin >> x >> y >> z;
	C3D point3(x, y, z);
	cout << point3.getDistance3() << endl;
	C2D point4(x, y);
	cout << point4.getDistance() << endl;
	return 0;
}


/*
��Ŀ����
����һ��ƽ���ϵĵ�C2D�࣬������һ��getDistance()�ĳ�Ա����������õ㵽ԭ��ľ��룻��C2D����������ά�ռ�ĵ�C3D�࣬����getDistance()��Ա��������õ㵽ԭ��ľ��롣�Էֱ�����һ��C2D��C3D�Ķ��󣬼������ǵ�ԭ��ľ��롣
��ά�ռ�����㣨x, y, z���ͣ�x1, y1, z1���ľ��빫ʽ���£�
[(x-x1)^2+(y-y1)^2+(z-z1)^2]^(1/2)
����
��һ�ж�ά�����λ��

�ڶ�����ά�����λ��1

��������ά�����λ��2

���
��һ�ж�ά�����λ�õ�ԭ��ľ���

�ڶ�����ά�����λ��1��ԭ��ľ���

��������ά�����λ��2��ԭ��ľ���

��������ά�����λ��2��ֵ����ά���������󣬶�ά����㵽ԭ��ľ���

��������
3 4
3 4 5
6 8 8
�������
5
7.07107
12.8062
10
*/