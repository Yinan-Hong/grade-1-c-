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
题目描述
银行账户包括余额、利率、号码、类型等属性，其中号是固定8位整数，类型表示个人还是企业账户，如果是个人用P标识，企业用E标识。
账户又分为活期账户和定期账户，活期利率为0.5%，定期利率为1.5%。
账户操作有计息、查询操作。计息操作是根据利率计算利息，并把利息增加到余额中，并做相关信息输出。查询操作是输出账户的全部信息。
创建一个活期账户，并通过构造函数初始化各个属性。然后通过拷贝构造来创建一个定期账户，信息与活期账户基本相同，不同之处包括：定期账户号码是活期账户号码加50000000（7个0）；利率是定期利率。
要求所有数据成员都是私有属性
用C++语言的类与对象思想来编写程序实现上述要求


输入
输入测试个数t，表示有t个活期账户
先输入一个活期账户的账户号码、账户类型、余额（根据输入创建活期账户和定期账户）
接着输入两个操作符，第一个操作符对活期账户操作，第二个操作符对定期账户进行操作。若输入大写字母C表示计息操作，若输入大写字母P表示查询操作
以此类推输入其他账户的信息和操作


输出
每两行输出一对活期账户和定期账户的操作结果。

样例输入
2
12345678 P 10000
C P
23456789 E 20000
P C
样例输出
Account=12345678--sum=10050
Account=62345678--Person--sum=10000--rate=0.015
Account=23456789--Enterprise--sum=20000--rate=0.005
Account=73456789--sum=20300
*/