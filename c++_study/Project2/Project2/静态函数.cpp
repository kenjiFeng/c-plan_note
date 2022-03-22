#include <iostream>
using namespace std;
#include <string>

class person {
	/*person(int a,int b) {
		a = a;
		b = b;
	}*/
public:
	static void func() {
		cout << "bµÄÖµÎª" << b << endl;

	}
	int a;
	static int	b;
};
int person::b = 10;

//int main() {
//	person c;
//	c.func();
//
//}