////#include<iostream>
////using namespace std;
////#include<string>
//
//
//
////������
////������ֻ�ܵ��ó�����������̬�����Ĺ���һ��
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
//		this->b--;				//����һ��ǰ�õ�--���أ������õ�������Ϊ����ʽ��Ӧ
//		return *this;
//	}
//
//	person operator--(int) {
//		person a;
//		//�ȼ�¼��ǰ��ֵ
//		a.b = this->b;
//		this->b--;
//		//�󷵻�
//		return a;
//	}
//
//private:
//	void show_private() {
//		cout << "����˽�к���" << endl;
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
