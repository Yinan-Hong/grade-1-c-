#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (; t > 0; t--) {
		int n, sum;
		sum = 0;
		cin >> n;
		int weight[100];
		
		for (int i = 0; i < n; i++) {
			cin >> weight[i];
			sum += weight[i];
		}
		int average = sum / n;
		int count=0;
		for (int i = 0; i < n; i++) {
			if (weight[i] > average)count++;
		}
		cout << count << endl;
	}
	
	return 0;
}

/*
��Ŀ����
������������ÿ���������Ų�ͬ�����ء�
����һ�����ܵ����أ��������泬��ƽ�����ص�����������
����
��һ���������T����ʾ��T������ʵ��
�ڶ����������n����ʾ��һ�����ܵ�����������������n�����ܵ�����
�Դ�����
���
���ÿһ�������У�����ƽ�����ص�����������
��������
2
3
1 2 3
4
10 20 30 40
�������
1
2
*/