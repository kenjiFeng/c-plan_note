#include <iostream>
#include<string>
using namespace std;
#include"ѧ����ͷ�ļ�.h"



//�ж������˵ĳɼ��Ƿ����
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
//		cout << "���˵ĳɼ����" << endl;
//	}
//	system("pause");
//
//
//}


//class person {
//public:
//	person() {
//		cout << "����Ĭ���޲ι��캯��" << endl;
//	}
//	~person()
//	{
//		cout << "������������" << endl;
//
//	}
//
//	int age;
//};

//���ú������ص��ÿ�������
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
//	cout << "C������Ϊ" << C.age<<endl;
//	system("pause");
//	return 0;
//		
//}


//ǳ���������
class person {
public:
	person() {
		cout << "Ĭ�Ϲ���" << endl;
	}
	person(int vage, int aheight) {
		age = vage;
		height = new int(aheight);
		cout << "��������" << endl;
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
		cout << "������������" << endl;
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















