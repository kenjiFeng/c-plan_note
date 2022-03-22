#include "学生类头文件.h"

//显示姓名和学号的函数
void	student::lista() {
	cout << "姓名为： " << name << endl;
	cout << "学号为： " << s_ID << endl;
	cout << "成绩为： " << chengji << endl;

}
void student::setchengji(int a) {
	chengji = a;
}
int student::getchengji() {
	return	chengji;
}

//成员函数判断是否两个成绩相等
bool student::issame(student &a) {
	if (getchengji() == a.getchengji())
	{
		return true;
	}
}
