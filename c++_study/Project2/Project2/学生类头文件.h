#pragma once
#include <iostream>	
using namespace std;
#include	<string>
//在类的头文件声明，不需要写类中具体函数，只需要写声明
//在源文件当中也需要添加该头文件才能够使用
//在源文件中只要添加该类的头文件，写好函数表达式即可使用

class student
{
public:
	string name;
	int s_ID;
	//显示姓名和学号的函数
	void lista();
	void setchengji(int a);
	int getchengji();

	//成员函数判断是否两个成绩相等
	bool issame(student &a);


private:
	int chengji;
};

