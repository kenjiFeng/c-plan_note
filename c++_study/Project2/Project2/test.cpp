#include <iostream>
using namespace std;
#include <string>

//����һ����ջ������
int* test(){
	int *p = new int(10);
	
	return p;
}
int* test01() {
	int*aa = new int[10];
	aa[0] = 1;
		return aa;
}
//int main() {
	//int *a = test();
	//cout << *a << endl;
	//int *b = test01();
	//b = { 0 };
	//cout << *b << endl;
//}
