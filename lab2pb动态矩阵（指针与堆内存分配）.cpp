#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int** array;
		int m, n;
		cin >> m >> n;
		array = new int* [m];
		for (int i = 0; i < m; i++) {
			array[i] = new int[n];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> array[i][j];
			}
		}
		int max = array[0][0];
		int min = array[0][0];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (array[i][j] > max) {
					max = array[i][j];
				}
				if (array[i][j] < min) {
					min = array[i][j];
				}
			}
		}
		cout << min << " " << max << endl;
		for (int i = 0; i < m; i++) {
			delete[] array[i];
		}
		delete[] array;
	}
	return 0;
}

/*
��Ŀ����
δ֪һ����������Ĵ�С���ڳ�������ʱ�Ż�������������m������n

Ҫ��ʹ��ָ�룬���new��������̬����һ����ά���飬������þ������Сֵ�����ֵ������ʹ�������±귨��

�����ȴ���һ���������Ȼ��ֻʹ�þ����һ���ֿռ����������ݷ��ʡ�

�����ľ����С��������������m������nһ��

����
��һ������t��ʾt������ʵ��

�ڶ���������������m��n����ʾ��һ�����������������

����������������m�У�ÿ��n�����֣���ʾ�����һ���������ֵ

��������t��ʵ��

���
ÿ�����һ��ʵ������Сֵ�����ֵ

��������
2
2 3
33 22 11
66 88 55
3 4
19 38 45 14
22 65 87 31
91 35 52 74
�������
11 88
14 91
*/