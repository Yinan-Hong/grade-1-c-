#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (; t> 0; t--) {
		int a, b, c,d;
		d = 0;
		cin >> a >> b >> c;
		if (a + b > c&& b == c) {
			d = 1;
		}
		else { d = 0; }
		cout << d << endl;
	}
	return 0;
}

/*
��Ŀ����
�����±��ʽ������ֵ��a��b��c���������������Ƕ���С��100����Ȼ��
a+b>c&&b==c

����
��һ������T����ʾ������T������ʾ��
�ڶ��п�ʼ��ÿ������3������ֵ������T��
���
ÿ�����������
��������
3
5 6 7
4 5 5
6 1 9
�������
0
1
0
*/