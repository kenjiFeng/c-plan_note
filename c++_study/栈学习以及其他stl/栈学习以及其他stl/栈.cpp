#include<map>
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
#include<algorithm>
#include<string>
#include<set>
#include<ctime>
#include<list>


#define DEPA 0
#define DEPB 1
#define DEPC 2


class worker
{
public:
	string name;
	int salary;

};

void createworker(vector<worker> &v) {
	string a = "ABCDEFGHIJ";
		for (int i = 0; i < 10; ++i) {
			worker w1;
			w1.name = "员工：";
			w1.name += a[i];
			w1.salary = rand() % 1000 + 4000;
			v.push_back(w1);
		}


}

void setgroup(vector<worker> &v, multimap<int, worker> &m) {
	for (vector<worker>::iterator k = v.begin(); k != v.end(); ++k) {
		int a = rand() % 3;
		m.insert(make_pair(a, *k));

	}

}

void showall_worker(multimap<int, worker> &m) {
	multimap<int, worker>::iterator pos = m.find(DEPA);
	int count = m.count(DEPA);
	int index = 0;
	for ( ;pos!=m.end()&&index<count;pos++, index++){
		cout << "名字为    " << pos->second.name <<"    薪酬为" << pos->second.salary << endl;
	}
	cout << "DEPA的人数为：" << count << endl;

	 pos = m.find(DEPB);
	 count = m.count(DEPB);
	 index = 0;
	for (; pos != m.end() && index < count; pos++,index++) {
		cout << "名字为    " << pos->second.name << "    薪酬为" << pos->second.salary << endl;
	}
	cout << "DEPB的人数为：" << count << endl;

	pos = m.find(DEPC);
	count = m.count(DEPC);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		cout << "名字为    " << pos->second.name << "薪酬为    " << pos->second.salary << endl;
	}
	cout << "DEPC的人数为：" << count << endl;



}


//函数对象类的，仿函数
class BBB {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

void list_init() {
	list<int> L;
	for (int i; i < 10; ++i) {
		L.push_back(i);
	}
	

}


int main() {
	/*srand((unsigned int)time(NULL));
	vector<worker> vworker;
	createworker(vworker);
	multimap<int, worker> map1;
	setgroup(vworker,map1);
	showall_worker(map1);*/






	system("pause");
}

