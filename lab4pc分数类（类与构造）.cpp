#include <iostream>
#include <iomanip>
using namespace std;

class CFraction
{
private:
    int fz, fm;
public:
    CFraction();
    CFraction(int fz_val, int fm_val);
    CFraction add(const CFraction& r);
    CFraction sub(const CFraction& r);
    CFraction mul(const CFraction& r);
    CFraction div(const CFraction& r);
    int getGCD();   // �����ķ��Ӻͷ�ĸ�����Լ��
    void print();
};

CFraction::CFraction(){}

CFraction::CFraction(int fz_val, int fm_val){
    fz = fz_val;
    fm = fm_val;
}

CFraction CFraction::add(const CFraction& r) {
    return CFraction(fz * r.fm + fm * r.fz, fm * r.fm);
}

CFraction CFraction::sub(const CFraction& r) {
    return CFraction(fz * r.fm - fm * r.fz, fm * r.fm);
}

CFraction CFraction::mul(const CFraction& r) {
    return CFraction(fz * r.fz, fm * r.fm);
}

CFraction CFraction::div(const CFraction& r) {
    return CFraction(fz * r.fm, fm * r.fz);
}

int fabs(int a) {
    if (a < 0)
        return -a;
    else
        return a;
}

int CFraction::getGCD() {
    int r = fm;
    int a = fabs(fz), b = fabs(fm);
    while (a % b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

void CFraction::print() {
    int gcd = getGCD();
    fz /= gcd;
    fm /= gcd;
    string sign;
    if (fz / fz == fm / fm)
        sign = "";
    else
        sign = "-";
    if (fm != 1) {
        cout << sign << fz << "/" << fm << endl;
    }
    else
        cout << sign << fz;
}

int main() {
    int t, fz, fm;
    char s;
    cin >> t;
    CFraction c;
    while (t--) {
        cin >> fz >> s >> fm;
        CFraction a(fz, fm);
        cin >> fz >> s >> fm;
        CFraction b(fz, fm);
        c = a.add(b);
        c.print();
        c = a.sub(b);
        c.print();
        c = a.mul(b);
        c.print();
        c = a.div(b);
        c.print();
        cout << endl;
    }
    return 0;
}










/*
������з������ʵ��:
class CFraction
{
private:
     int fz, fm;
public:
     CFraction(int fz_val, int fm_val) ;
     CFraction add(const CFraction &r);
     CFraction sub(const CFraction &r);
     CFraction mul(const CFraction &r);
     CFraction div(const CFraction &r);
     int getGCD();   // �����ķ��Ӻͷ�ĸ�����Լ��
     void print();
};
������a��b�����Լ���ɲ���շת��������ֳ�ŷ������㷨���䲽��Ϊ:
1. ����a, bʹa > b;
2. ��a��b�õ�����r,��r=0,��bΪ���Լ��,�˳�.
3. ��r��Ϊ0,����b����a, r����b,��ʱa,b������һ�ε�С,�����ģ��С��;
4. ������2����
����
�������ݵ����� t
��һ���һ������
��һ��ڶ�������
�ڶ����һ������
�ڶ���ڶ�������
......
���
��һ�����������ĺ�
��һ�����������Ĳ�
��һ�����������Ļ�
��һ��������������
�ڶ������������ĺ�
�ڶ������������Ĳ�
�ڶ������������Ļ�
�ڶ���������������
......
��������
3
1/2
2/3
3/4
5/8
21/23
8/13
�������
7/6
-1/6
1/3
3/4

11/8
1/8
15/32
6/5

457/299
89/299
168/299
273/184

*/