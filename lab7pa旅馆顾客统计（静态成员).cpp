#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class Hotel {
public:
	Hotel(char* a_Customer) {
		m_CustomerName = new char[strlen(a_Customer) + 1];
		strcpy(m_CustomerName, a_Customer);
		m_TotalCustNum++;
		m_CustomerID = 20150000 + m_TotalCustNum;
		m_TotalEarning += m_Rent;
	}

	~Hotel() {
		delete[] m_CustomerName;
	}

	void Display();
	static void setprice(float price);

private:
	static int m_TotalCustNum;
	static float m_TotalEarning;
	static float m_Rent;
	char* m_CustomerName;
	int m_CustomerID;
};

int Hotel::m_TotalCustNum = 0;
float Hotel::m_Rent = 0;
float Hotel::m_TotalEarning = 0;

void Hotel::Display() {
	cout << m_CustomerName << ' ' << m_CustomerID << ' ' << m_TotalCustNum << ' ' << m_TotalEarning << endl;
}

void Hotel::setprice(float price) {
	m_Rent = price;
}

int main() {
	float price;
	cin >> price;
	char* name = new char[200];
	Hotel::setprice(price);
	while (cin >> name && name[0] != '0') {
		Hotel customer(name);
		customer.Display();
	}
	delete[] name;
	return 0;
}




/*
��Ŀ����
��д����ͳ��ĳ�ù�ס�޿��˵������������ܶҪ��������˵�������������˱�ţ�2015+˳��ţ�˳���4λ�����1λΪ0001����2λΪ0002���������ƣ����������������Լ������ܶ�������������ܶ��þ�̬��Ա���������Բ�����ͨ�����ݳ�Ա���ù����������£�




����
��1�У������ùݵ����˿ͷ���
��2�п�ʼ����������˿�������0��ʾ���������

���
ÿ����������˿���Ϣ�͵�ǰ�ù���Ϣ�������˿��������˿ͱ�ţ��ùݵ�ǰ���������ùݵ�ǰ�����롣

��������
150
���� ���� ���� 0
�������
���� 20150001 1 150
���� 20150002 2 300
���� 20150003 3 450
*/