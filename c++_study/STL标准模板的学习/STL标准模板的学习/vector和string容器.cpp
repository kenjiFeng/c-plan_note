
#include<string>
using namespace std;
#include<vector>
#include<algorithm>

void printaa(int val){
	cout << val << endl;
}
void test() {
	vector<int>v; //������һ����������
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	v.push_back(15);
	vector<int>::iterator aa = v.begin(); //����һ����ʼ��������ָ�������еĵ�һ��Ԫ��
	vector<int>::iterator	bb = v.end(); //����һ��������������ָ�������е����һ������һ��Ԫ��
	//�����ı�����ӡ����
	/*for (aa ;aa!=bb ; aa++)
	{
		cout << *aa << endl;
	}*/
	//for_each()����������stl
	for_each(v.begin(), v.end(), printaa);


}

//vector ����Զ�����������
class person {
public:
	person(string name, int age) {
		this->age = age;
		this->name = name;
	}
	string name;
	int age;
};
void printclass(person &a) {
	cout <<a.name<< endl;
	cout << a.age << endl;

}
void test_class() {
	vector<person*>aa;
	person p1("aa", 11);
	aa.push_back(&p1);
	//for_each(aa.begin(), aa.end(), printclass);  //�����Ҫ���ָ�룬������������������ķ�������֤�������
	for (vector<person*>::iterator k = aa.begin(); k != aa.end(); ++k){
		cout << (*k)->name << endl;
		cout << (*k)->age << endl;
	}

}

//22������Ƕ������
void test03() {
	vector<vector<int>>aa;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;
	for (int i = 0; i < 4; ++i) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
		v5.push_back(i + 5);
	}
	aa.push_back(v1);
	aa.push_back(v2);
	aa.push_back(v3);
	aa.push_back(v4);
	aa.push_back(v5);
	for (vector<vector<int>>::iterator k = aa.begin(); k != aa.end(); ++k) {
		for (vector<int>::iterator k1 = (*k).begin(); k1 != (*k).end(); ++k1) {
			cout << *k1 << endl;
		}
	}


}


//string���캯��
void test03() {
	//string���������������ָ�룬charΪָ��
	string aa;
	const char *str = "hello";
	string bb(aa); //Ĭ�Ϲ��캯��
	string cc(str); //����char��ʼ���ַ���
	string dd(10, 'e'); //����10���ַ������ַ���dd
}
//string��ֵ��ƴ�Ӳ���
void test04() {
	string str1;
	str1 = "aa";
	string str2;
	str2 = str1;
	string str3; string str5;
	str3 = 'b';
	str5.assign("hellosasda", 5); //��ǰ5���ַ���ֵ��str5
	str1 += str2;  //ƴ�Ӳ���
	str1 += 'e';
	str1.append("asdaffas",1, 3); //��ǰ���3���ַ�ƴ����str1��

}
//string�е��ַ������Һ��滻
void test06() {
	string str1 = "abcdefg";
	int aa = str.find("de");  //�ɹ����Ҽ�����λ�ã����ɹ���Ϊ-1
	str.replace(1, 3, "1111"); //�ӵ�һ�������������滻�ɺ�����ַ���
}
//string�е��ַ����Ĳ����ɾ�����Ӵ�
void test07() {
	string s1 = "aaassdqw";
	s1.insert(2, "asd");//����
	str.erase(1, 3);//�ӵ�һ����ʼ��ɾ3��
	str.substr(1, 3); //�ӵ�һ����ʼ����ȡ3��
}

//vector���顢����������������ܹ���̬���ٿռ䡢��̬��չ������̬��չ����ֱ���ں��濪չ�ռ�
//�������ҳ�һ������Ŀռ�󣬽�ԭ�������ݿ�����ȥ���ͷ�ԭ���Ŀռ�






int main() {
	
	system("pause");
	return 0;
}