#include <iostream>
using namespace std;
int main() {
	for (int i = 0; i < 100; ++i) {
		int a = i %10; //打印出个位数
		int b = i / 10;//打印出十位数
		int c = i % 7; //判断是否是7的倍数
		
		if (a == 7 || b == 7 || c == 0) 
			cout << "焯" << endl;
		else
		{
			cout << i << endl;
		}
			
			

		}
	for (int a = 1; a <= 10; ++a) {
		for (int b = 1; b < a; ++b) {
			cout << b << "*" << a << "=" << b * a << " ";
			
		}
		cout << endl;
	}
	}
	




