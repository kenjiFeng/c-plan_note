#include <iostream>
using namespace std;
#include <string>


class person {
public:



	int age;
	int	*height;

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
		if (height != NULL) {
			delete height;
			height = NULL;
		}
		height = new int(*a.height);
		//height =a.height  
		cout << "copy����" << endl;   //��ǳ�㿽���У����û�����¿��ٶ��������е�ָ��ָ����������ʱ��ᵼ��һ���ڴ��ظ������������ڴ�й©
	}								//����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ��������������	

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
		cout << "������������" << endl;
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
