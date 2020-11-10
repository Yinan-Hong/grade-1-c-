#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class Robot {
private:
	char* name;
	int hp;
	int damage;
	int defend;
	char type;
	int level;
public:
	void set(char t) {
		switch (t) {
		case 'N':
			hp = 5 * level;
			damage = 5 * level;
			defend = 5 * level; break;
		case'A':
			hp = 5 * level;
			damage = 10 * level;
			defend = 5 * level; break;
		case'D':
			hp = 5 * level;
			damage = 5 * level;
			defend = 10 * level; break;
		case'H':
			hp = 50 * level;
			damage = 5 * level;
			defend = 5 * level; break;
		}
	}
	Robot(char* n, char t, int lev) {
		name = new char[10];
		strcpy(name, n);
		type = t;
		level = lev;
		set(t);
	}
	static void transform(Robot* r, char t);
	void print() {
		cout << name << "--" << type << "--" << level << "--" << hp << "--" << damage << "--" << defend << endl;
	}
	static int count;

	~Robot() {
		delete[]name;
	}
};

int Robot::count = 0;

void Robot::transform(Robot* r, char t) {
	if (t != r->type) {
		r->type = t;
		r->set(t);
	count++;
	}
}

int main() {
	int t, l;
	char type1, type2;
	char* n = new char[10];
	cin >> t;
	while (t--) {
		cin >> n >> type1 >> l;
		cin >> type2;
		Robot robot(n, type1, l);
		Robot::transform(&robot, type2);
		robot.print();
	}
	cout << "The number of robot transform is " << Robot::count << endl;
	delete[]n;
}


/*
题目描述
编写一个机器人类，包含属性有机器名、血量、伤害值、防御值、类型和等级。其中血量、伤害和防御和等级、类型相关：
普通型机器人，类型为N，血量、伤害、防御是等级的5倍
攻击型机器人，类型为A，攻击是等级的10倍，其他属性和普通的一样
防御型机器人，类型为D，防御是等级的10倍，其他属性和普通的一样
生命型机器人，类型为H，生命是等级的50倍，其他属性和普通的一样。
机器人操作包括：打印、各个属性的获取和设置方法，构造函数可有可无，根据需要自行编写，
编写一个全局函数用于机器人变身，使得各种类型机器人能够相互转变。参数包括机器人对象指针和变身后的机器人类型，功能是修改机器人类型，并更改相关的属性。如果变身类型和机器人原来的类型不同，则执行变身功能，并返回true；如果变身类型和原来类型相同，则不执行变身，并返回false.
要求所有数据成员都是私有属性，用C++语言和面向对象设计思想来编程实现上述要求











输入
第一行输入t，表示要执行t次机器人变身
接着每两行，一行输入一个机器人的属性，包括机器名、类型、等级，另一行输入变身类型
依次类推输入

输出
每行输出变身后的机器人信息，要求调用机器人的打印方法来输出，即使机器人不变身也输出
属性输出依次为：名称、类型、等级、血量、伤害、防御
最后一行输出执行变身的次数

样例输入
3
X001 N 5
H
X002 A 5
D
X003 D 5
D
样例输出
X001--H--5--250--25--25
X002--D--5--25--25--50
X003--D--5--25--25--50
The number of robot transform is 2
*/