#include <iostream>
using namespace std;

class Student {
public:
	string name;
	string number;
	string college;
	string major;
	string gender;
	string dorm;
	string tel;
};

int main() {
	int t;
	cin >> t;
	Student stu[10];
	for (int i = t; i > 0; i--) {
		cin >> stu[i].name >> stu[i].number >> stu[i].college >> stu[i].major >> stu[i].gender >> stu[i].dorm >> stu[i].tel;
	}
	for (int i = t; i > 0; i--) {
		cout << stu[i].name <<" "<< stu[i].number <<" "<< stu[i].college <<" "<< stu[i].major <<" "<< stu[i].gender <<" " << stu[i].dorm <<" "<< stu[i].tel<<endl;
	}
	return 0;
}


/*
��Ŀ����
   ������������Ƶ����ľ��ǰѿ͹��������Ϊ����������һ�ζδ��룬У԰���������ѧ����������ѧ�������ܶ����ԣ�����������ѧ�š�����ѧԺ��רҵ���Ա�סַ����ϵ�绰�������������ȵȣ�����Щ���ԣ���Ҫ�������ǵĶ����������ȡ������������������ȡѧ�š�����ѧ�š������������ȵȣ���������ǿ���˵�����Ժͷ������������Ժͷ������������з��ʿ��Ʒ�ʽ���ƣ���ʾΪpublic��private��protected�ȣ��������ϵ���Ϣ�������һ��������ѧ���ඨ�壺Student�����������n���������ĸ�������ֵ��
����
��һ�б�ʾҪ����n������
�����������벻ͬ����ĸ�����ֵ��ÿ������һ�С�
���
�����ͬ����ĸ�������
ÿ������ռһ��
��������
2
WangHai 2014150112 ����� �������ѧ�뼼�� �� ����215 13760222222
LiBin 2013151292 ����� ������� �� ����318 13677777777
�������
WangHai 2014150112 ����� �������ѧ�뼼�� �� ����215 13760222222
LiBin 2013151292 ����� ������� �� ����318 13677777777
*/