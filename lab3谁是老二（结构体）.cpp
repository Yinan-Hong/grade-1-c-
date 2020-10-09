#include <iostream>
using namespace std;

struct Birthday {
	int day, month, year;
};

void swap(Birthday& a, Birthday& b) {
	Birthday temp = a;
	a = b;
	b = temp;
}

bool DateABiggerThanDateB(Birthday A, Birthday B) {
	if (A.year > B.year)
		return true;
	else if (A.year < B.year)
		return false;
	else {
		if (A.month > B.month)
			return true;
		else if (A.month < B.month)
			return false;
		else {
			return A.day > B.day;
		}
	}
}

Birthday sort(Birthday* birthday, int t) {
	for (int i = t-1; i > 0 ; i--) {
		for (int j = 0; j < i; j++) {
			if (DateABiggerThanDateB(birthday[j], birthday[j + 1]))
				swap(birthday[j], birthday[j + 1]);
		}
	}
	return birthday[1];
}

int main() {
	int t;
	cin >> t;
	struct Birthday birthday[10];
	for (int i = 0; i < t; i++) 
		cin >> birthday[i].year >> birthday[i].month >> birthday[i].day;
	struct Birthday sec = sort(birthday, t);
	cout << sec.year << "-" << sec.month << "-" << sec.day << endl;
	
	return 0;
}


/*
��Ŀ����
����һ���ṹ�壬���������գ���ʾһ��ѧ���ĳ������ڡ�Ȼ����һȺѧ���ĳ����������ҳ�˭�ĳ����������еڶ�
Ҫ�󣺳������ڵĴ洢����ʹ�ýṹ�壬����ʹ���������͵����ݽṹ��
Ҫ�����ȫ���̶Գ������ڵ����롢���ʡ����������ʹ�ýṹ��

����
��һ������t��ʾ��t����������
ÿ�����������������ֱ��ʾ�ꡢ�¡���
��������t��ʵ��

���
������еڶ��ϵĳ������ڣ�������-��-�յĸ�ʽ���

��������
6
1980 5 6
1981 8 3
1980 3 19
1980 5 3
1983 9 12
1981 11 23
�������
1980-5-3
*/