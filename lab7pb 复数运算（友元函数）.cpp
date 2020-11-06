#include <iostream>
using namespace std;

class Complex {
public:
	Complex() {};
	Complex(double r, double i) {
		real = r;
		imag = i;
	}
	friend Complex addCom(Complex &c1, Complex &c2);
	friend Complex minusCom(Complex& c1, Complex& c2);
	friend void outCom(Complex c);

private:
	double real;
	double imag;
};

Complex addCom(Complex& c1, Complex& c2) {
	Complex temp;
	temp.real = c1.real + c2.real;
	temp.imag = c1.imag + c2.imag;
	return temp;
}

Complex minusCom(Complex& c1, Complex& c2) {
	Complex temp;
	temp.real = c1.real - c2.real;
	temp.imag = c1.imag - c2.imag;
	return temp;
}

void outCom(Complex c) {
	cout << '(' << c.real << ',' << c.imag << ')' << endl;
}

int main() {
	double r, i;
	int t;
	char sign;
	cin >> r >> i >> t;
	Complex c1(r, i);
	while (t--) {
		cin >> sign >> r >> i;
		Complex c2(r, i);
		if (sign == '+') {
			outCom(addCom(c1, c2));
			c1 = addCom(c1, c2);
		}
		if (sign == '-') {
			outCom(minusCom(c1, c2));
			c1 = minusCom(c1, c2);
		}
	}
	return 0;
}

/*
��Ŀ����
��������������£�

Ҫ�����£�
1.     ʵ�ָ��������Ԫ����addCom��outCom��


2.   �ο�addCom����Ϊ����������һ����Ԫ����minusCom������ʵ�����������ļ���
3.     ��main�����У�ͨ����Ԫ������ʵ�ָ����ļӼ����͸����������


����
��1�У���1��������ʵ�����鲿
��2�У����������Ĵ�����ע�⣺���������㡣�������ɲο�����
  ��3�п�ʼ��ÿ�������������ͣ��Լ���������ĸ�����ʵ�����鲿����+����ʾ������ӣ���-����ʾ���������

���
 ÿ��������������Ľ�������������ʽΪ��(ʵ��,�鲿)����

��������
10 10
3
+ 20 10
- 15 5
+ 5 25
�������
(30,20)
(15,15)
(20,40)
*/