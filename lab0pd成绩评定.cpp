#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (; t > 0; t--) {
		float result;
		cin >> result;
		if (result >= 85) {
			cout << "A" << endl;
		}
		else if(result>=75){
			cout << "B" << endl;
		}
		else if (result >= 65) {
			cout << "C" << endl;
		}
		else if (result >= 60) {
			cout << "D" << endl;
		}
		else {
			cout << "F" << endl;
		}
	}
	return 0;
}

/*
��Ŀ����
���ڸ���0��100֮��ĳɼ����гɼ����������ڵ���85��A��75����85������B��65��75��������C��60��65��������D��60��������F

����
��һ������T��ʾ��T������ʵ��
�ڶ�����ÿ������1���ɼ�����������T��
���
����ɼ��ȼ�
��������
3
0
55
78
�������
F
F
B
*/