#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		const char* month[] = { "January","February","March","April","May","June","July","Aguest","September","October","November","December" };
		int i;
		cin >> i;
		if (i > 0 && i < 13) {
			cout << month[i - 1] << endl;
		}
		else {
			cout << "error" << endl;
		}

	}
	return 0;
}

/*
��Ŀ����
��֪ÿ���·ݵ�Ӣ�ĵ������£�Ҫ�󴴽�һ��ָ�����飬�����е�ÿ��ָ��ָ��һ���·ݵ�Ӣ���ַ�����Ҫ�����������·����������Ӧ��Ӣ�ĵ���
1�� January
2�� February
3�� March
4�� April
5�� May
6�� June
7�� July
8�� Aguest
9�� September
10�� October
11�� November
12�� December
����
��һ������t��ʾt������ʵ��

����ÿ������һ���·ݵ�����

��������t��

���
ÿ�������Ӧ���·ݵ��ַ�������û������·ݵĵ��ʣ����error

��������
3
5
11
15
�������
May
November
error
*/