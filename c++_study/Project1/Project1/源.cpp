#include <iostream>
using namespace std;
int main() {
	for (int i = 0; i < 100; ++i) {
		int a = i %10; //��ӡ����λ��
		int b = i / 10;//��ӡ��ʮλ��
		int c = i % 7; //�ж��Ƿ���7�ı���
		
		if (a == 7 || b == 7 || c == 0) 
			cout << "��" << endl;
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
	




