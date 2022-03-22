#include<iostream>
using namespace std;
#include<fstream>


class person {
public:
	char m_a[1024];
	int m_age;
	person(){}
	person(char *a,int age) {
		for (int i = 0; i < 1024; ++i) {
			m_a[i] = a[i];
		}
		m_age = age;
	}
};





void test(){  //写入文件
	ofstream ofs;
	ofs.open("test.txt", ios::app);
	//ios::out 代表写入
	//ios::in 代表读数据//ios::ate 代表从后面读
	////ios::app 代表添加新的材料
	//ios::trunc 代表是删除当前的文件重新写入
	ofs << "nihao" << endl;
	ofs.close();
}
void test01() {  //读取文件
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	//ios::out 代表写入
	//ios::in 代表读数据//ios::ate 代表从后面读
	////ios::app 代表添加新的材料
	//ios::trunc 代表是删除当前的文件重新写入
	//读取数据；
	if (ifs.is_open()) {
		cout << "打开成功" << endl;
	}
	else
	{
		cout << "打开失败" << endl;
		return;
	}
	//第一种打开文件的方式
	char aa[1024] = { 0 };
	/*while (ifs>>aa)
	{
		cout << aa << endl;
	}
	ifs.close();*/
	while (ifs.getline(aa,1024))
	{
		cout << aa << endl;
	}
	ifs.close();
}


void test02() {
	char aa[1024] = { "牛逼哥" };
	person a(aa,18);
	cout << a.m_a << a.m_age << endl;
	ofstream abs{ "person.txt",ios::binary | ios::out };  //写入文件的格式
	abs.write((const char *)&a, sizeof(a));
	
	abs.close();
}
void test03(){    //打开二进制文件
	ifstream bbs;
	bbs.open( "person.txt",ios::binary | ios::out );
	if (bbs.is_open()) {
		cout << "dakaichenggong" << endl;

	}
	else
	{
		cout << "dakaishibai" << endl;
		return;
	}
	person a;
	bbs.read((char *)&a, sizeof(a));
	cout << a.m_a << a.m_age << endl;
	bbs.close();
}

int main() {

	test02();
	test03();
	return 0;
}
