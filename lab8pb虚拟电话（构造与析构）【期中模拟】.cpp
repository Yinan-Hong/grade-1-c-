#include <iostream>
#include <string.h>
using namespace std;

class Phone {
private:
	int number;
	char type;
	int status;
	string name;
public:
	Phone(int no, char t, int s, string n) {
		number = no;
		type = t;
		status = s;
		name = n;
		cout << number << " constructed." << endl;
	}
	~Phone() {
		cout << number << " destructed." << endl;
	}
	void print() {
		cout << "Phone=" << number << "--Type=" << type << "--State=" ;
		if (status)
			cout << "use";
		else
			cout << "unuse";
		cout << "--Owner=" << name << endl;
	}
	bool check(int no) {
		if (no == number)return true;
		else return false;
	}
};

int main() {
	int num, s, t;
	string name;
	char type;
	cin >> num >> type >> s >> name;
	Phone p1(num, type, s, name);
	cin >> num >> type >> s >> name;
	Phone p2(num, type, s, name);
	cin >> num >> type >> s >> name;
	Phone p3(num, type, s, name);
	cin >> t;
	while (t--) {
		cin >> num;
		if (p1.check(num))
			p1.print();
		else if (p2.check(num))
			p2.print();
		else if (p3.check(num))
			p3.print();
		else
			cout << "wrong number." << endl;
	}
	return 0;
}




/*
��Ŀ����
����绰�������ԣ��绰�š�״̬������������
1���绰����һ���࣬��������������ͣ����к������������ͣ������õ�����ĸ��ʾ�û����A��ʾ������B��ʾ��ҵ��C��ʾ���ˡ�������������졢���ԵĻ�ȡ�����õȷ�����������Ҫ���б�д��
2��״̬��һ�����ֱ�ʾ��1��ʾ���ã�0��ʾδ�ã�
3������������һ���ַ���

�绰�������������졢��������ӡ�Ͳ�ѯ��
1�����캯����Ҫ���Ǹ������Ա�Ĺ��죬���������ʾ��Ϣ������绰����Ϊ12345678�����캯�����"12345678 constructed."
2����ӡ������绰�������Ϣ����������绰״̬�����������use��״̬��δ�������unuse�������ʽ��ʾ����
3�����������������ʾ��Ϣ������绰��Ϊ12345678���������������"12345678 destructed. "
4����ѯ�����Ǹ��ݸ����ĺ����ѯ�绰������绰�������͸������벻��ͬ���򷵻�0������绰�������͸���������ͬ���򷵻�1

��C++���������˼��ʵ������Ҫ��
1������������ݣ����������绰���󣬲�ͨ�����췽����ʼ����
2���������ɸ��绰���룬ͨ����ѯ������ѯ��Щ�����Ƿ��������绰�����У�������������"wrong number."����������ô�ӡ��������绰��Ϣ�����忴���������





����
ͷ�������������绰��Ϣ��ÿ�а����绰���롢�绰���͡�״̬����������
����һ������t����ʾ��t������Ҫ��ѯ
����t������t���绰����


���
t�����t������Ĳ�ѯ���

��������
80000001 A 1 tom
80000002 B 0 ken
80000003 C 1 mary
3
50000002
80000003
80000002
�������
80000001 constructed.
80000002 constructed.
80000003 constructed.
wrong number.
Phone=80000003--Type=C--State=use--Owner=mary
Phone=80000002--Type=B--State=unuse--Owner=ken
80000003 destructed.
80000002 destructed.
80000001 destructed.
*/