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
void swapaa(T&a, T&b) {   //模板必须推导出相同的数据类型才可进行
							//模板必须要确定出T的数据类型才可使用
	T temp;
	temp = a;
		a = b;
		b = temp;
}
template<class A>
void fun() {
	cout << "调用的是函数fun" << endl;
}

void test() {
	double a = 1.11;
	double b = 2.22;
	swapaa(a, b);
	fun<int>();
	cout << a << b << endl;
}




//排序的模板案例
//规则为从小到大
//算法选择
//测试char数组和int数组

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

//类模板
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


