#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (; t > 0; t--) {
		int length, height, depth;
		cin >> length >> height >> depth;
		int area = 2 * length * height + 2 * depth * length + 2 * height * depth;
		cout << area << endl;

	}
	return 0;
}

/*
��Ŀ����
����һ��������ĳ���ߣ��������ı����

����
��һ���������T����ʾ��T������ʵ��
�ڶ�������һ��������ĳ���ߣ�����߾�ΪС��100��������
�Դ�����

���
���ÿ��������ı����

��������
2
1 2 3
4 5 6
�������
22
148
*/