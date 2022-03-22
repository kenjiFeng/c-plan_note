////#include<iostream>
////using namespace std;
////#include<string>
//
//
//
////常函数
////常对象只能调用常函数，跟静态变量的规则一样
//class	person {
//public:
//	friend void test1();
//	void showperson()const{
//		this->m_a = 10;
//		//b = 5;
//	}
//	mutable int m_a;
//	 int b;
//	void func() {
//		cout << "hello" << endl;
//	}
//	person operator+(person &b) {
//		//person a;
//		this->b += b.b;
//		return *this;
//
//	}
//	person& operator--() {
//		this->b--;				//这是一个前置的--重载，加引用的作用是为了链式反应
//		return *this;
//	}
//
//	person operator--(int) {
//		person a;
//		//先记录当前的值
//		a.b = this->b;
//		this->b--;
//		//后返回
//		return a;
//	}
//
//private:
//	void show_private() {
//		cout << "这是私有函数" << endl;
//	}
//};
//
//void test1() {
//	const	person a;
//	person b;
//	b.b = 5;
//	a.showperson();
//	b.show_private();
//	person c;
//	c.b = 10;
//	b = b+c;
//	cout <<b.b<< endl;
//	cout <<-- b.b << endl;
//	cout << b.b-- << endl;
//	cout << b.b << endl;
//
//}
////
////int main() {
////	test1();
////	return 0;
////}
//
