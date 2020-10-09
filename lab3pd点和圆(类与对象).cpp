#include <iostream>
#include <cmath>
using namespace std;

//class define

class Point {
public:
    void Setpoint(double x, double y);
private:
    double point_x;
    double point_y;
};

class Circle {
public:
    void SetCenter(double x, double y);
    void SetRadius(double r);
    double getArea(double r);
    double getlen(double r);
    bool Contain(double x, double y);

private:
    double circle_x;
    double circle_y;
    double circle_r;
};

//class achieve

void Point::Setpoint(double x, double y) {
    point_x = x;
    point_y = y;
}

void Circle::SetCenter(double x, double y) {
    circle_x = x;
    circle_y = y;
}

void Circle::SetRadius(double r) {
    circle_r = r;
}

double Circle::getArea(double r) {
    return 3.14 * r * r;
}

double Circle::getlen(double r) {
    return 3.14 * 2 * r;
}

bool Circle::Contain(double x, double y) {
    return sqrt((x - circle_x) * (x - circle_x) + (x - circle_y) * (x - circle_y)) < circle_r;
}

//main

int main() {
    double px, py, cx, cy, cr;
    cin >> cx >> cy >> cr >> px >> py;
    Circle c;
    Point p;
    c.SetCenter(cx, cy);
    c.SetRadius(cr);
    double area = c.getArea(cr);
    double len = c.getlen(cr);
    cout << area << " " << len << endl;
    if (c.Contain(px, py)) {
        cout << "yes" << endl;
    }
    else
        cout << "no" << endl;
	return 0;
}


/*
��Ŀ����
���һ������Point���������ԣ�x�����y���꣬�������趨���꣨SetPoint������ȡx���꣨GetX������ȡy���꣨GetY��
���һ��Բ��Circle���������ԣ�Բ������x��y���뾶r������������
1. �趨Բ�ģ�SetCenter��������Բ��x�����y����
2. �趨�뾶��SetRadius�������ð뾶����
3. ���������getArea�������㹫ʽ�����=3.14*r*r
4. �����ܳ���getLength�������㹫ʽ���ܳ�=2*3.14*r
5. ������Contain�����ж�һ��Բ�Ƿ����һ���㣬����Բ�ĵ������ľ��룬Ȼ��Ͱ뾶���Ƚϣ������򲻰�����С�ڵ��������
ע�⣺�ύ����ʱ������ע�ͻ��ֳ����������ඨ�塢��ʵ�֡�������������
//-----�ඨ��------
class XXX
{  // д�ඨ�����
};
//----��ʵ��------
void XXX::Process()
{ // д�ඨ�����
};
//-----������-----
int main()
{
  //�Զ���һЩ����
  //����һ��Բ�����һ�������
 //����Բ����͵�����������ֵ��������ʼ��
 //���Բ�������Բ���ܳ�
//���Բ�Ƿ�����㣬���������yes���������no
  return 0;
}
����
��һ������Բ������������Բ�ĵ�x��y���꣬�뾶
�ڶ�������������������x��y����
���
��һ�����Բ��������ܳ������֮���ÿո������������ȵ�С�����2λ
�ڶ������Բ�Ƿ�����㣬���������yes���������no

��C++�У����ָ�����ȵĲο��������£�

#include <iostream>
#include <iomanip> //����������ͷ�ļ�
using namespace std;
void main( )
{ double a =3.14;
  cout<<fixed<<setprecision(3)<<a<<endl;  //���С�����3λ

��������
1 1 1
2 2
�������
3.14 6.28
no
��ʾ

���������Ĺ�ʽ dis =sqrt [ (x1-x2)^2  + (y1-y2)^2 ] �� ^2��ʾƽ����sqrt��ʾ��ƽ����������ʽֻ�Ǳ�ʾ���壬������ʵ����

��C++ʹ��sqrt����������ƽ������ͷ�ļ�����cmath
*/