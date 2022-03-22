#include <iostream>
#include<string>
using namespace std;
#include"学生类头文件.h"



//判断两个人的成绩是否相等
bool	isxiangdeng(student &a,student &b) {
	if (a.getchengji() == b.getchengji())
	{
		return true;
	}
}






//int main() {
//	student a;
//	a.name = "fengzhiikun";
//	a.s_ID = 123456;
//	a.setchengji(100);
//	a.lista();
//	student b;
//	b.name = "kkge";
//	b.setchengji(100);
//	b.s_ID = 151515;
//	b.lista();
//	
//	bool ret = isxiangdeng(a, b);
//
//	if (ret)
//	{
//		cout << "两人的成绩相等" << endl;
//	}
//	system("pause");
//
//
//}


//class person {
//public:
//	person() {
//		cout << "调用默认无参构造函数" << endl;
//	}
//	~person()
//	{
//		cout << "调用析构函数" << endl;
//
//	}
//
//	int age;
//};

//利用函数返回调用拷贝函数
//person copyfunc(person &a) {
//	person b;
//	b = person(a);
//	return b;
//
//}


//
//int main() {
//	person a;
//	a.age = 10;
//	person C = copyfunc(a);
//	cout << "C的年龄为" << C.age<<endl;
//	system("pause");
//	return 0;
//		
//}


//浅拷贝和深拷贝
class person {
public:
	person() {
		cout << "默认构造" << endl;
	}
	person(int vage, int aheight) {
		age = vage;
		height = new int(aheight);
		cout << "参数构造" << endl;
	}
	person(const person &a) {
		//height = a.height;
		age = a.age;
		height = new int(*a.height);
	}

	~person() {
		if (height != NULL) {
			delete height;
		}
		cout << "析构函数调用" << endl;
	}




	int age;
	int	*height;


};


//int main() {
//	person a(18,180);
//	int kk = 155;
//	a.height = &kk;
//	//person b = person(a);
//	cout << a.height << endl;
//
//}















