#include<iostream>
#include<string>
using namespace std;


//void swap(double &a, double &b) {
//	double temp;
//	temp = a;
//	a = b;
//	b = temp;
//}
//
//
//void swap(int &a, int &b) {
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//}
template<class T>
void swapaa(T&a, T&b) {   //ģ������Ƶ�����ͬ���������Ͳſɽ���
							//ģ�����Ҫȷ����T���������Ͳſ�ʹ��
	T temp;
	temp = a;
		a = b;
		b = temp;
}
template<class A>
void fun() {
	cout << "���õ��Ǻ���fun" << endl;
}

void test() {
	double a = 1.11;
	double b = 2.22;
	swapaa(a, b);
	fun<int>();
	cout << a << b << endl;
}




//�����ģ�尸��
//����Ϊ��С����
//�㷨ѡ��
//����char�����int����

template<class B>
void sort_tem(B a[],int c) {
	//int c =sizeof(a[])/sizeof(a[0])
		for (int i = 0; i < c; ++i) {
			int min = i;
			for (int j = i + 1; i < c; ++j) {
				if (a[j] < a[min]) {
					min = j;
				}
					
			}
			if (min != i) {
				B d = a[i];
				a[i] = a[min];
				a[min] = d;
			}


		}
	return;
}

//��ģ��
template<class nametype,class agetype>
class person {
public:
	person(nametype name, agetype age) {
		this->name = name;
		this->age;
	}

	nametype name;
	agetype age;
};






int main() {
	
}


