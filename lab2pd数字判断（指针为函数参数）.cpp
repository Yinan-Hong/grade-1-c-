#include <iostream>
using namespace std;

int isNumber(char *a,int size) {
	int num=0;
	for (int i = 0; i < size; i++) {
		if (a[i] < '0' || a[i]>'9') {
			return -1;
		}
		else {
			num = num * 10 + a[i]-'0';
		}
	}
	return num;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		char* a = new char[10];
		cin >> a;
		int size = 0;
		for (int i = 0; a[i] != '\0'; i++) {
			size++;
		}
		int num = isNumber(a,size);
		cout << num << endl;
		delete[] a;
	}
	
	return 0;
}

/*
��Ŀ����
����һ���ַ������ж�����ַ����Ƿ�һ����ȫ����ֵ���ַ�������������"1234"����ô��ʾ����1234������"12a3"�ͱ�ʾֻ��һ���ַ���������һ������

Ҫ���д����isNumber��������һ���ַ�ָ�룬����ֵ����������

����ַ�����ʾһ������������������������ҷ���

����ַ������Ǳ�ʾһ���������򷵻�-1

�������������isNumber���ж��ַ���������ʹ���κ�C++�Դ�������������ƺ���

����
����t��ʾ��t������ʵ��

ÿ������һ���ַ���

��������t��

���
ÿ������жϽ��

��������
3
1234
567a
0890
�������
1234
-1
890
*/