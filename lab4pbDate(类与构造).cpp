#include <iostream>
#include <iomanip>
using namespace std;

class Date {
	int year, month, day;
public:
	Date();
	Date(int y, int m, int d);
	int getYear();
	int getMonth();
	int getDay();
	void setDate(int y, int m, int d);
	void print();
	void addOneDay();
};

Date::Date(){
	year = 1900;
	month = 1;
	day = 1;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::getYear(){
	return year;
}

int Date::getMonth() {
	return month;
}

int Date::getDay() {
	return day;
}

void Date::setDate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

void Date::print() {
	cout <<year << "/" << setfill('0') << setw(2) << month << "/" << setfill('0') << setw(2) << day << endl;
}

void Date::addOneDay() {
	int dmax;
	day++;
	if (month == 2) {
		if (year % 4 == 0 && year / 100 != 0 || year % 400 == 0)
			dmax = 29;
		else
			dmax = 28;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		dmax = 31;
	else
		dmax = 30;
	if (day > dmax) {
		day = day - dmax;
		month++;
	}
	if (month > 12) {
		month -= 12;
		year++;
	}
}

int main() {
	int y, m, d, t, c;
	cin >> t;
	c = 2;
	while (t--) {
		cin >> y >> m >> d;
		if (c % 2 == 0) {
			Date date(y, m, d);
			cout << "Today is ";
			date.print();
			date.addOneDay();
			cout << "Tomorrow is ";
			date.print();
		}
		else {
			Date date;
			date.setDate(y, m, d);
			cout << "Today is ";
			date.print();
			date.addOneDay();
			cout << "Tomorrow is ";
			date.print();
		}
		c++;
	}
}








/*
������һ��������Ķ��壬��������ʵ�������еķ��������������������ɶ������֮��


ע�⣬���ж���������ʱ��Ҫ������¡����ꡢ������ж�
����9.��30�յ�������10��1�գ�12��31�յ������ǵڶ����1��1��
2��28�յ�����Ҫ�����Ƿ����꣬��������2��29�գ�����������3��1��

����
�������ݵ�����t
��һ��������ݵ��� �� ��
..........
Ҫ���һ�����ڵ������ճ�ʼ�����ù��캯�����ڶ������ڵ������ճ�ʼ������setDate�����������������ֲ��ù��캯�������ĸ������ֲ���setDate�������Դ����ơ�


���
������������
������������
��������
4
2012 1 3
2012 2 28
2012 3 31
2012 4 30
�������
Today is 2012/01/03
Tomorrow is 2012/01/04
Today is 2012/02/28
Tomorrow is 2012/02/29
Today is 2012/03/31
Tomorrow is 2012/04/01
Today is 2012/04/30
Tomorrow is 2012/05/01
*/