#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<deque>
#include<ctime>
using namespace std;

class person {
public:
	person(string name, int score) {
		this->name = name;
		this->score = score;
	}
	string name;
	int score;
};

void creat_person(vector<person>&v) {
	string str = "ABCDE";

	for (int i = 0; i < 5; ++i) {
		string name = "ѡ��";
		name += str[i];
		person p(name, 0);
		v.push_back(p);
	}

}

void score(vector<person>&v) {


	for (int j = 0; j < v.size(); j++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int k = rand() % 41 + 60;
			d.push_back(k);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		int sum = 0;
		for (int i = 0; i < d.size(); i++) {
			sum += d[i];
		}
		int arg;
		arg = sum / d.size();
		v[j].score = arg;
		//cout << v[j].name << "����Ϊ�� " << v[j].score << endl;
	}
}
void show(vector<person> &v) {
	for (vector<person>::iterator v1 = v.begin(); v1 != v.end(); ++v1) {
		cout << "ѡ������ ��" << v1->name << "�÷� ��" << v1->score << endl;
	}
}


//int main() {
//
//	srand((unsigned int)time(NULL));
//	vector<person> v;
//	creat_person(v);
//	score(v);
//	show(v);
//	system("pause");
//
//}