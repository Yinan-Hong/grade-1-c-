#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point {
	double x, y;
public:
	Point();
	Point(double x_value, double y_value);
	double getX();
	double getY();
	void setX(double x_value);
	void setY(double y_value);
	double distanceToAnotherPoint(Point p);
};

Point::Point(){}

Point::Point(double x_value, double y_value) {
	x = x_value;
	y = y_value;
}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

void Point::setX(double x_value) {
	x = x_value;
}

void Point::setY(double y_value) {
	y = y_value;
}

double Point::distanceToAnotherPoint(Point p) {
	return sqrt((pow(x - p.getX(), 2)) + (pow(y - p.getY(), 2)));
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		double x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Point p1(x1,y1);
		Point p2(x2, y2);
		cout << "Distance of Point(" << fixed << setprecision(2) << p1.getX() << "," << p1.getY() << ") to Point(" << p2.getX() << "," << p2.getY() << ") is " << p1.distanceToAnotherPoint(p2) << endl;
	}
	return 0;
}


/*
������һ��ƽ���ϵĵ���ඨ�壬��������ʵ���������з����������ɵ��������


����
�������ݵ����� t
��һ��������ݵ�p1��x����   ��һ��������ݵ�p1��y����  ��һ��������ݵ�p2��x����   ��һ��������ݵ�p2��y����
..........
���
���p1��p2�ľ���
��C++�У����ָ�����ȵĲο��������£�

#include <iostream>
#include <iomanip> //����������ͷ�ļ�
using namespace std;
void main( )
{ double a =3.141596;
  cout<<fixed<<setprecision(3)<<a<<endl;  //���С�����3λ
}


��������
2
1 2 3 4
-1 0.5 -2 5
�������
Distance of Point(1.00,2.00) to Point(3.00,4.00) is 2.83
Distance of Point(-1.00,0.50) to Point(-2.00,5.00) is 4.61
*/