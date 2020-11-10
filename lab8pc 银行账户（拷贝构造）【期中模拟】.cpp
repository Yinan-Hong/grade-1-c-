#include <iostream>
using namespace std;

class Bank {
private:
	int money;
	float rate;
	int number;
	char type;
public:
	Bank(int m, int n, char t) {
		money = m;
		number = n;
		type = t;
		rate = 0.005;
	}
	Bank(Bank& b) {
		money = b.money;
		number = b.number + 50000000;
		type = b.type;
		rate = 0.015;
	}

	void countprint(char cp) {
		if (cp == 'C') {
			money += money * rate;
			cout << "Account=" << number << "--sum=" << money << endl;
		}
		if (cp == 'P') {
			cout << "Account=" << number << "--";
			if (type == 'E')
				cout << "Enterprise";
			if (type == 'P')
				cout << "Person";
			cout << "--sum=" << money << "--rate=" << rate << endl;
		}
	}
};

int main() {
	int t, num, money;
	char type, cp;
	cin >> t;
	while (t--) {
		cin >> num >> type >> money;
		Bank account(money, num, type);
		Bank account2(account);
		cin >> cp;
		account.countprint(cp);
		cin >> cp;
		account2.countprint(cp);
	}
	return 0;
}






/*
��Ŀ����
�����˻����������ʡ����롢���͵����ԣ����к��ǹ̶�8λ���������ͱ�ʾ���˻�����ҵ�˻�������Ǹ�����P��ʶ����ҵ��E��ʶ��
�˻��ַ�Ϊ�����˻��Ͷ����˻�����������Ϊ0.5%����������Ϊ1.5%��
�˻������м�Ϣ����ѯ��������Ϣ�����Ǹ������ʼ�����Ϣ��������Ϣ���ӵ�����У����������Ϣ�������ѯ����������˻���ȫ����Ϣ��
����һ�������˻�����ͨ�����캯����ʼ���������ԡ�Ȼ��ͨ����������������һ�������˻�����Ϣ������˻�������ͬ����֮ͬ�������������˻������ǻ����˻������50000000��7��0���������Ƕ������ʡ�
Ҫ���������ݳ�Ա����˽������
��C++���Ե��������˼������д����ʵ������Ҫ��


����
������Ը���t����ʾ��t�������˻�
������һ�������˻����˻����롢�˻����͡����������봴�������˻��Ͷ����˻���
����������������������һ���������Ի����˻��������ڶ����������Զ����˻����в������������д��ĸC��ʾ��Ϣ�������������д��ĸP��ʾ��ѯ����
�Դ��������������˻�����Ϣ�Ͳ���


���
ÿ�������һ�Ի����˻��Ͷ����˻��Ĳ��������

��������
2
12345678 P 10000
C P
23456789 E 20000
P C
�������
Account=12345678--sum=10050
Account=62345678--Person--sum=10000--rate=0.015
Account=23456789--Enterprise--sum=20000--rate=0.005
Account=73456789--sum=20300
*/