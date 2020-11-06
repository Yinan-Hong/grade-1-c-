#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Account {
public:
	Account(){}
	Account(string accno, string name, float balance);
	~Account();
	void Deposit(float amount);
	void Withdraw(float amount);
	float GetBalance();
	void Show();
	static int GetCount();
	static float GetInterestRate();
	friend float Update(Account& a);
	static void setInterest(float i);
	void setbalance(float b);
	static void setcount(float b);

private:
	static int count;
	static float InterestRate;
	string _accno, _accname;
	float _balance;
};

int Account::count = 0;
float Account::InterestRate = 0;

Account::Account(string accno, string name, float balance) {
	_accno = accno;		//strcpy(_accno, accno);
	_accname = name;	//strcpy(_accname, name);
	_balance = balance;
}

Account::~Account(){}

void Account::Deposit(float amount) {
	_balance += amount;
}

void Account::Withdraw(float amount) {
	_balance -= amount;
}

float Account::GetBalance() { return _balance; }

void Account::Show() {
	cout << _accno << ' ' << _accname << ' ';
}

int Account::GetCount() { return count; }

float Account::GetInterestRate() { return InterestRate; }

float Update(Account& a) {
	return a._balance +a._balance * a.InterestRate;
}

void Account::setInterest(float i) {
	InterestRate = i;
}

void Account::setbalance(float b) {
	_balance = b;
}

void Account::setcount(float b) {
	count += b;
}

int main() {
	int n;
	string acc, name;
	float i, b, d, w;
	cin >> i >> n;
	int j = n;
	Account::setInterest(i);
	while (j--) {
		cin >> acc >> name >> b >> d >> w;
		Account a(acc, name, b);
		a.Show();
		a.Deposit(d);
		cout << a.GetBalance() << ' ';
		a.setbalance(Update(a));
		cout << a.GetBalance() << ' ';
		a.Withdraw(w);
		cout << a.GetBalance() << endl;
		a.setcount(a.GetBalance());
 	}
	cout << Account::GetCount() << endl;


	return 0;
}

/*
��Ŀ����
�����˻���Ļ����������£�


Ҫ�����£�
ʵ�ָ������˻���
Ϊ�˻���Account����һ����Ԫ������ʵ���˻���Ϣ��Ҫ�������Ϣ�������Ϣ���=�˻����+�˻����*���ʣ�����Ԫ����������ʽΪ friend void Update(Account& a);
��main�����У�����һ��Account���͵�ָ�����飬��ÿ��ָ��ָ��̬�����Account���󣬲����ó�Ա�������Դ�ȡ���ʾ�Ⱥ������ٵ�����Ԫ�������Խ��н�Ϣ��
��ҿ��Ը���ʵ�������������������������Ҳ�����޸ĳ�Ա�����Ĳ�������



����
��1�У�����
��2�У��˻���Ŀn
��3�п�ʼ��ÿ����������һ���˻��ġ��˺š��������������������������ȡ������
���
��1�п�ʼ��ÿ�����һ���˻��������Ϣ�������˺š�������������������Ϣ��ȡ�����
���һ����������˻�����

��������
0.01
3
201501 ���� 10000 1000 2000
201502 ���� 20000 2000 4000
201503 ���� 80000 4000 6000
�������
201501 ���� 11000 11110 9110
201502 ���� 22000 22220 18220
201503 ���� 84000 84840 78840
106170
*/