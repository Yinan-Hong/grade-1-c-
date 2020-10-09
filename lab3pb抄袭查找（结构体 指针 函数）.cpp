#include <iostream>
using namespace std;

struct Paper {
	int number;
	char ans_1[20];
	char ans_2[20];
	char ans_3[20];
};

bool judge(char* pa, char* pb) {
	int len = 0;
	int same = 0;
	while (*pa != '\0' && *pb != '\0') {
		if (*pa == *pb)
			same++;
		len++;
		pa++;
		pb++;
	}
	return same >= 0.9 * len;
}

int cmp(Paper A, Paper B) {
	int c = 3;
	char* pa = A.ans_1;
	char* pb = B.ans_1;
	if (judge(pa, pb))
		return 1;
	pa = A.ans_2;
	pb = B.ans_2;
	if (judge(pa, pb))
		return 2;
	pa = A.ans_3;
	pb = B.ans_3;
	if (judge(pa, pb))
		return 3;
	return 0;
}

int main() {
	int t;
	cin >> t;
	struct Paper paper[10];
	for (int i = 0; i < t; i++) 
		cin >> paper[i].number >> paper[i].ans_1 >> paper[i].ans_2 >> paper[i].ans_3;
	for (int i = 0; i < t-1 ; i++) {
		for (int j = i+1; j < t; j++) {
			if (int z=cmp(paper[i], paper[j])) {
				cout << paper[i].number << " " << paper[j].number << " " << z << endl;

			}
		}
	}

	return 0;
}


/*
��Ŀ����
��֪һȺѧ���Ŀ����Ծ�Ҫ����Ծ����ݽ��жԱȣ������Ƿ��г�Ϯ��
ÿ���Ծ������ѧ�ţ��������ͣ�����Ŀ1�𰸣��ַ������ͣ�����Ŀ2�𰸣��ַ������ͣ�����Ŀ3�𰸣��ַ������ͣ�
Ҫ��ʹ�ýṹ�����洢�Ծ����Ϣ������һ������������ֵΪһ�������������������ṹ��ָ�룬���������ǱȽ������Ծ��ÿ����Ŀ�Ĵ𰸣������ͬ��ŵĴ����ƶȳ���90%����ô����Ϊ�г�Ϯ���������س�Ϯ��ţ����򷵻�0�����ƶ���ָ��ͬһ��Ŀ�У������𰸵����λ���ϵ��ַ������Ƚϣ���ͬ���������ڵ�����һ���𰸵ĳ��ȵ�90%������Ϊ��Ϯ��

����
��һ������t��ʾ��t���Ծ�
�ڶ��������1���Ծ��ѧ��ѧ��
�����������1���Ծ����Ŀ1��
�����������1���Ծ����Ŀ2��
�����������1���Ծ����Ŀ3��
ÿ���Ծ��Ӧ4������
��������t���Ծ������
���
��һ���У��ѷ��ֳ�Ϯ������ѧ�ź���Ŀ�ţ�����֮���õ����ո����
�����������Ŀ1��Ϯ����Ŀ��Ϊ1���Դ�����
���˳���������ѧ��˳��������
��������
5
2088150555
aabcdef11
ZZ887766dd
cc33447799ZZ
2088150333
abcdef00
AABBCCDDEE
ZZ668899cc
2088150111
AABBCCDDEE
ZZ668899cc
abcdef00
2088150222
AABBCFDDeE
ZZ889966dd
abcdef000
2088150444
aabcdef00
AABBCDDDEE
cc668899ZZ
�������
2088150333 2088150444 2
2088150111 2088150222 3
*/