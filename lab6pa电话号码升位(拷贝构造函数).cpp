#include<iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class CTelNumber {
	char* p;
public:
	CTelNumber(){
		p = new char[10];
	}
	CTelNumber(char* q) {
		p = new char[10];
		strcpy(p, q);
	}
	CTelNumber(CTelNumber& q) {
		p = new char[10];
		if (q.p[0] == '2' || q.p[0] == '3' || q.p[0] == '4') {
			p[0] = '8';
		}
		else
			p[0] = '2';
		for (int i = 0; i < 7; i++) 
			p[i + 1] = q.p[i];
		p[8] = '\0';
		}
	void print() {
			cout << p<<endl;
	}
	~CTelNumber() {
		delete p;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		char* q;
		int flag = 1;
		q = new char[10];
		cin >> q;
		for (int i = 0; i < 7; i++) {
			if (q[i] < '0' || q[i]>'9') {
				flag = 0;
				break;
			}
			if (q[0] == '0' || q[0] == '9'||q[0]=='1')
				flag = 0;
		}
		if (flag) {
			if (strlen(q) == 7) {
				CTelNumber m(q);
				CTelNumber n(m);
				n.print();
			}
			else
				cout << "Illegal phone number" << endl;
			}
		else
			cout << "Illegal phone number" << endl;
	}
	return 0;
}

/*
��Ŀ����
����һ���绰������CTelNumber,����1���ַ�ָ�����ݳ�Ա,�Լ����졢��������ӡ���������캯����
�ַ�ָ�������ڶ�̬����һ���ַ����飬Ȼ�󱣴���������ĵ绰����
���캯���Ĺ�����Ϊ�������ü��������7λ�绰���룬
�������캯���Ĺ�������ԭ��7λ����Ķ�����λΪ8λ�������,Ҳ����˵��������Ķ�����Դ���������.�绰��λ�Ĺ�����ԭ2��3��4��ͷ�ĵ绰����ǰ���8��ԭ5��6��7��8��ͷ��ǰ���2��
ע��:�绰����ֻ��ȫ���������ַ�������������������������Ϊ�Ƿ�)
����
�������ݵ����� t
��һ��7λ����
�ڶ���7λ����
......
���
��һ��������λ��ĺ���
�ڶ���������λ��ĺ���
......
��������������ɹ��������������Ϣ�����忴ʾ��
��������
3
6545889
3335656
565655
�������
26545889
83335656
Illegal phone number
*/