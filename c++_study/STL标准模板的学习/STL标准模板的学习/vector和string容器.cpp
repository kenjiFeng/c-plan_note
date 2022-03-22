
#include<string>
using namespace std;
#include<vector>
#include<algorithm>

void printaa(int val){
	cout << val << endl;
}
void test() {
	vector<int>v; //创建了一个容器数组
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	v.push_back(15);
	vector<int>::iterator aa = v.begin(); //创建一个起始迭代器，指向容器中的第一个元素
	vector<int>::iterator	bb = v.end(); //创建一个结束迭代器，指向容器中的最后一个的下一个元素
	//常见的遍历打印操作
	/*for (aa ;aa!=bb ; aa++)
	{
		cout << *aa << endl;
	}*/
	//for_each()操作，内置stl
	for_each(v.begin(), v.end(), printaa);


}

//vector 存放自定义数据类型
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
	//for_each(aa.begin(), aa.end(), printclass);  //如果需要存放指针，可以利用下面迭代器的方法，保证不会出错
	for (vector<person*>::iterator k = aa.begin(); k != aa.end(); ++k){
		cout << (*k)->name << endl;
		cout << (*k)->age << endl;
	}

}

//22、容器嵌套容器
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


//string构造函数
void test03() {
	//string基本上是类而不是指针，char为指针
	string aa;
	const char *str = "hello";
	string bb(aa); //默认构造函数
	string cc(str); //利用char初始化字符串
	string dd(10, 'e'); //利用10个字符创建字符串dd
}
//string赋值和拼接操作
void test04() {
	string str1;
	str1 = "aa";
	string str2;
	str2 = str1;
	string str3; string str5;
	str3 = 'b';
	str5.assign("hellosasda", 5); //把前5个字符赋值给str5
	str1 += str2;  //拼接操作
	str1 += 'e';
	str1.append("asdaffas",1, 3); //把前面的3个字符拼接在str1上

}
//string中的字符串查找和替换
void test06() {
	string str1 = "abcdefg";
	int aa = str.find("de");  //成功查找即返回位置，不成功则为-1
	str.replace(1, 3, "1111"); //从第一个到第三个都替换成后面的字符串
}
//string中的字符串的插入和删除、子串
void test07() {
	string s1 = "aaassdqw";
	s1.insert(2, "asd");//插入
	str.erase(1, 3);//从第一个开始，删3个
	str.substr(1, 3); //从第一个开始，截取3个
}

//vector数组、与数组的区别在于能够动态开辟空间、动态扩展，而动态扩展不是直接在后面开展空间
//而是在找出一个更大的空间后，将原来的数据拷贝进去，释放原来的空间






int main() {
	
	system("pause");
	return 0;
}