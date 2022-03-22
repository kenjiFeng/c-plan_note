#include <iostream>
using namespace std;
#include <string>


class person {
public:



	int age;
	int	*height;

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
		if (height != NULL) {
			delete height;
			height = NULL;
		}
		height = new int(*a.height);
		//height =a.height  
		cout << "copy构造" << endl;   //在浅层拷贝中，如果没有重新开辟堆区让类中的指针指向，在析构的时候会导致一块内存重复析构，导致内存泄漏
	}								//如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题	

	person& operator=(person &a) {
		this->age = a.age;
		if (height != NULL) {
			delete height;
			height = NULL;
		}
		this->height = new int(*a.height);
		return *this;
	}

	~person() {
		if (height != NULL) {
			delete height;
		}
		cout << "析构函数调用" << endl;
	}





};


int main() {
	person a(18, 180);
	int kk = 100;
	person b = person(a);
	//a.height = &kk;
	//person b = person(a);
	cout << *b.height << endl;

	person aa(19, 200);
	person bb;
	bb = aa;
	cout << *bb.height << endl;

	system("pause");
}
