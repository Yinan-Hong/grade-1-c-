#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (; t > 0; t--) {
		float result;
		cin >> result;
		if (result >= 85) {
			cout << "A" << endl;
		}
		else if(result>=75){
			cout << "B" << endl;
		}
		else if (result >= 65) {
			cout << "C" << endl;
		}
		else if (result >= 60) {
			cout << "D" << endl;
		}
		else {
			cout << "F" << endl;
		}
	}
	return 0;
}

/*
题目描述
对于给出0～100之间的成绩进行成绩评定，大于等于85是A，75分至85以下是B，65至75分以下是C，60至65分以下是D，60分以下是F

输入
第一行输入T表示有T个测试实例
第二行起，每行输入1个成绩，连续输入T行
输出
输出成绩等级
样例输入
3
0
55
78
样例输出
F
F
B
*/