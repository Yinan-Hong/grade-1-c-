#include <iostream>
using namespace std;

int cpm(char* p1, char* p2,int l) {
	int count=0;
	while (l--) {
		if (*p1 > * p2)count++;
		if (*p1 < *p2)count--;
		p1++;
		p2++;
	}
	return count;
}

int length(char *str) {
	int i = 0;
	while (*(str+i) != '\0') {
		i++;
	}
	return i;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		char str1[100];
		char str2[100];
		char* p1 = str1;
		char* p2 = str2;
		cin >> str1 >> str2;
		if (length(p1) != length(p2)) {
			if (length(p1) > length(p2))cout << 1 << endl;
			if (length(p1) < length(p2))cout << -1 << endl;
		}
		else {
			int count = cpm(p1, p2, length(str1));
			if (count > 0)cout << 1<<endl;
			if (count < 0)cout << -1 << endl;
			if (count == 0)cout << 0 << endl;
		}
	}
	return 0;
}

/*
��Ŀ����
��дһ�������Ƚ������ַ����������������ַ�ָ�루Ҫ����ʽ���壬����char *S, char *T)���Ƚ��ַ���S��T�Ĵ�С�����S����T���򷵻�1�����SС��T�򷵻�-1�����S��T����򷵻�0��
�ȽϹ���
1.�������ַ�������ͬλ���ϵ��ַ����бȽϣ��ַ��Ĵ�С�Ƚ���ASCIIֵΪ׼

2.�ڱȽ��У�����ַ���S���ַ������ַ���T���ַ�����������С�ڵ�����������ΪS����T�����������S����T�����С����SС��T
����SΪaaccdd��TΪeebbbb��ÿ��λ�ñȽϵõ�Sǰ������ĸ��С��T������4����ĸ������T��������ΪS����T
3.��������ַ������Ȳ�ͬ����������ַ���Ϊ��
�������������������ַ����������øú��������жϣ����жϺ����б���ʹ�ú���������ָ������ַ��Ƚ�

����
����t��ʾ��t������ʵ��
����ÿ�������������ַ���
��������t��ʵ��

���
ÿ�����һ��ʵ���ıȽϽ��


��������
3
aaccdd
eebbbb
AAbb++
aaEE*-
zznnkk
aaaaaaa
�������
1
0
-1
*/