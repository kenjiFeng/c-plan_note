#include<string>
#include<iostream>
using namespace std;
#include"������ģ��.hpp"



void print_out(arra<int> a);

void test() {
	arra<int>tex(5);
	tex.push_in(5);
	tex.push_in(5);
	tex.push_in(5);
	tex.pop_out();
	print_out(tex);
}

void print_out(arra<int> a) {
	for (int i = 0; i < a.m_size; i++)
	{
		cout << a.arr[i] << endl;
	}
}




int main() {
	test();
	
	system("pause");
	return 0;

}