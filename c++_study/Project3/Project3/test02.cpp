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





void test(){  //д���ļ�
	ofstream ofs;
	ofs.open("test.txt", ios::app);
	//ios::out ����д��
	//ios::in ���������//ios::ate ����Ӻ����
	////ios::app ��������µĲ���
	//ios::trunc ������ɾ����ǰ���ļ�����д��
	ofs << "nihao" << endl;
	ofs.close();
}
void test01() {  //��ȡ�ļ�
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	//ios::out ����д��
	//ios::in ���������//ios::ate ����Ӻ����
	////ios::app ��������µĲ���
	//ios::trunc ������ɾ����ǰ���ļ�����д��
	//��ȡ���ݣ�
	if (ifs.is_open()) {
		cout << "�򿪳ɹ�" << endl;
	}
	else
	{
		cout << "��ʧ��" << endl;
		return;
	}
	//��һ�ִ��ļ��ķ�ʽ
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
	char aa[1024] = { "ţ�Ƹ�" };
	person a(aa,18);
	cout << a.m_a << a.m_age << endl;
	ofstream abs{ "person.txt",ios::binary | ios::out };  //д���ļ��ĸ�ʽ
	abs.write((const char *)&a, sizeof(a));
	
	abs.close();
}
void test03(){    //�򿪶������ļ�
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
