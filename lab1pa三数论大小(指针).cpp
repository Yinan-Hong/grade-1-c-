#include <iostream>
using namespace std;

void sort(int **p1, int **p2) {
		int temp;
		int* ptemp=&temp;
	if (**p2 > **p1) {

		*ptemp = **p2;
		**p2 = **p1;
		**p1 = *ptemp;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int* pointer_a = &a;
		int* pointer_b = &b;
		int* pointer_c = &c;
		sort(&pointer_a, &pointer_b);
		sort(&pointer_b, &pointer_c);
		sort(&pointer_a, &pointer_b);
		cout << *pointer_a << ' ' << *pointer_b << ' ' << *pointer_c << ' ' << endl;

	}
	return 0;
}

/*
��Ŀ����
��������������Ȼ���մӴ�С��˳�������ֵ��
Ҫ��������ָ��ֱ�ָ��������������������̱���ͨ��������ָ��������������ֱ�ӷ�������������
���ʱ������ʹ��������ָ�룬����ʹ�ô洢���������ı���

����
��һ������t��ʾ��t������ʵ��
�ڶ�����ÿ��������������
����t��

���
ÿ�а��մӴ�С��˳�����ÿ��ʵ��
��ÿ���У�ÿ����������󶼴���һ���ո񣬼�ʹ�������һ�����������ҲҪ�����һ���ո�

��������
3
2 4 6
88 99 77
111 333 222
�������
6 4 2
99 88 77
333 222 111
*/