#include <iostream>
#include <string.h>
using namespace std;

class Television {
private:
	int channel;
	int volumn;
	int t;
	int no;

public:
	static int tvCount;
	static int dvdCount;
	Television() {
		volumn = 50;
		t = 1;
	}
	void setNo(int n) {
		no = n;
		channel = n;
	}
	void set(int k, int x, int v) {
		t = k;
		channel = x;
		volumn = v;
	}
	int getk() {
		return t;
	}


	friend void remote(Television& tv, Television& re);

	void print() {
		cout << "��" << no << "�ŵ��ӻ�--";
		if (t == 1)
			cout << "TV";
		if (t == 2)
			cout << "DVD";
		cout<<"ģʽ--Ƶ��" << channel << "--����" << volumn << endl;
	}
};

int Television::tvCount = 0;
int Television::dvdCount = 0;

void remote(Television& tv, Television& re) {
	tv.t = re.t;
	tv.channel = re.channel;
	tv.volumn += re.volumn;
	if (tv.volumn > 100)
		tv.volumn = 100;
	if (tv.volumn < 0)
		tv.volumn = 0;
}

int main() {
	int n, t, i, k, x, v, no;
	cin >> n;
	Television* tv = new Television[n];
	Television::tvCount = n;
	for (int j = 0; j < n; j++) {
		tv[j].setNo(j + 1);
	}
	cin >> t;
	while (t--) {
		cin >> no >> k >> x >> v;
		if (tv[no - 1].getk() == 1 && k == 2) {
			Television::tvCount--;
			Television::dvdCount++;
		}
		if (tv[no - 1].getk() == 2 && k == 1) {
			Television::tvCount++;
			Television::dvdCount--;
		}
		Television rc;
		rc.set(k, x, v);
		remote(tv[no-1], rc);
		tv[no - 1].print();
	}
		cout << "���ŵ��ӵĵ��ӻ�����Ϊ" << Television::tvCount << endl;
		cout << "����DVD�ĵ��ӻ�����Ϊ" << Television::dvdCount << endl;

	return 0;
}








/*
��Ŀ����
���ӻ�����������ģʽ��Ƶ���ŵ����ԣ�����ģʽ��ΪTV��DVD���֡����ӻ���TVģʽ�£���������ӦƵ�������ݣ���DVDģʽ�£����ӻ�ʹ��ͳһ��Ƶ���Ų���DVD�����ݣ�Ƶ����ͳһΪ99�����⣬���ӻ����þ�̬��Ա�ķ��������������ݣ����ŵ��ӵĵ��ӻ������Ͳ���DVD�ĵ��ӻ���������ʼ��Ϊ0��

���ӻ�����������ӡ����ؾ�̬���������ԵĻ�ȡ�����õȣ�������Ҫ���б�д��
�ֱ�дһ��ң����������ͨ����Ԫ�����Ե��ӻ����п��ƣ����Ĳ����������ӻ�����ģʽ���仯������Ƶ���ţ��޷���ֵ����������������
1���Ե��ӻ��������ģʽ���ã��������ΪDVDģʽ����Ƶ���Ų���һ����99���������TVģʽ����Ҫ��Ƶ����������Ӧ��ֵ��
2�����ݱ仯�������е���������ԭ������Ϊ50��������仯����Ϊ-30����50-30=20����������Ϊ20������ֵ���Ϊ0�����Ϊ100��������Χ���������ٱ仯��
3�����µ�ǰ���ŵ��ӺͲ���DVD�ĵ��ӻ�����
4�����õ��ӻ�����Ĵ�ӡ����������������Ϣ
��ʾ��������ӻ�ԭ��ģʽ�Ͳ������ݵ�ģʽ����ͬ�ģ���ôʵ�ʲ������ǵ����������л�Ƶ���������Ϣ��
ע�⣺������һ������������һ�����ӻ����󣬲��������������ͣ������Ƕ��󡢻����ָ�롢��������ã�������Ҫ���б�д��
�ö�̬���鷽������n̨���ӻ�����1��ʼ��ţ�Ƶ����Ϊ��ţ�������ʼΪ50��ģʽΪTV��Ȼ��ͨ��ң���������Ե��ӻ����п��ơ�
����������ݳ�Ա����˽�����ԡ���ʹ��C++���Ժ��������˼����ʵ������Ҫ��

����
��һ������n����ʾ��n̨����̨
�ڶ�������t����ʾ��ִ��t��ң�ز���
��������t�У�ÿ������������ӻ����i��ģʽk��Ƶ����x�ͱ仯����������i��ʾ��į���ӻ���kΪ1��ʾTVģʽ��kΪ2��ʾDVDģʽ��

���
ÿ�����ִ��ң�ز�����ĵ��ӻ���Ϣ
���һ�������ǰ���ŵ��ӺͲ���DVD�ĵ��ӻ�������
�����ʽ������


��������
10
5
3 1 11 20
4 2 99 -20
5 2 99 80
5 1 55 -60
6 2 99 -70
�������
��3�ŵ��ӻ�--TVģʽ--Ƶ��11--����70
��4�ŵ��ӻ�--DVDģʽ--Ƶ��99--����30
��5�ŵ��ӻ�--DVDģʽ--Ƶ��99--����100
��5�ŵ��ӻ�--TVģʽ--Ƶ��55--����40
��6�ŵ��ӻ�--DVDģʽ--Ƶ��99--����0
���ŵ��ӵĵ��ӻ�����Ϊ8
����DVD�ĵ��ӻ�����Ϊ2
*/