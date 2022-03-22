#include<iostream>
#include<stdio.h>
#include"头文件管理.h"
using namespace std;
#include <vector>
#include<string>
#include<algorithm>
#include<deque>
#include<numeric>
#include<ostream>
#include<fstream>

Speechmanger::Speechmanger(){
	this->initSpeech();
	this->creat_speaker();
}
Speechmanger::~Speechmanger() {

}

void Speechmanger::creat_speaker() 
{
	string name = "ABCDEFGHIJKL";
	for (int i = 0; i < name.size(); ++i) {
		string name_sed = "选手";
		name_sed += name[i];

		speaker sp;
		sp.m_name =name_sed;
		for (int i = 0; i < 2; ++i) {
			sp.m_score[i] = 0;
		}
		this->v1.push_back(1001 + i);
		this->tester.insert(make_pair(i + 1001, sp));
	}
}


void Speechmanger::initSpeech() {
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->tester.clear();
	this->m_index = 1;
}


void Speechmanger::show_menu() {
	cout << "欢迎大家参加本次演讲比赛" << endl;
	cout << "1、开始演讲比赛" << endl;
	cout << "2、查看往届比赛记录" << endl;
	cout << "3、情况比赛记录" << endl;
	cout << "0、退出比赛程序" << endl;
	cout << endl;
}

void Speechmanger::chouqian() {
	cout << "开始抽签了" << endl;
	if (m_index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		cout << "第一轮抽签结果如下：" << endl;
		for (vector<int>::iterator k = v1.begin(); k != v1.end();
			++k) {
			cout << *k<<"  ";
		}
		system("pause");

	}
	else if(m_index == 2)
	{
		random_shuffle(v2.begin(), v2.end());
		cout << "第二轮抽签结果如下：" << endl;
		for (vector<int>::iterator k = v2.begin(); k != v2.end();
			++k) {
			cout << *k << "  ";
		}
		system("pause");
	}
}

void Speechmanger::bisai() {
	cout << "开始比赛啦" << endl;
	int num = 0;
	multimap<double, int, greater<double>> contain;
	vector<int>fangzhi;
	if (m_index == 1) {
		fangzhi = v1;
	}
	else if (m_index == 2)
	{
		fangzhi = v2;
	}
	for (vector<int>::iterator k = fangzhi.begin();
		k != fangzhi.end(); ++k) {
		deque<double> a;
		for (int i = 0; i < 10; ++i) {
			double b = (rand() % 401 + 600) / 10.f;
			a.push_back(b);
		}
		sort(a.begin(), a.end(), greater<double>());
		a.pop_back();
		a.pop_front();
		double sum = accumulate(a.begin(), a.end(), 0.0f);
		double avg = sum / a.size();
		this->tester[*k].m_score[m_index - 1] = avg;
		num++;
		contain.insert(make_pair(avg, *k));
		if (num % 6 == 0) {
			cout << "第" << num / 6 << "组" << "名次" << endl;
			for (multimap<double, int, greater<double>>::iterator k = contain.begin(); k != contain.end(); ++k) {
				cout << "姓名： " << this->tester[k->second].m_name <<"编号："
					<<k->second << "成绩： " << this->tester[k->second].m_score[m_index - 1] << endl;
			}
			system("pause");
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator k = contain.begin(); k != contain.end() && count < 3; ++k,count++) {
				if (this->m_index == 1) {
					v2.push_back(k->second);

				}
				else if(this->m_index == 2)
				{
					v3.push_back(k->second);
				}
			}

			contain.clear();
		}
		
		cout << endl;


	}
}



void Speechmanger::showjinji() {

	if (this->m_index == 1) {
		cout << "这是晋级赛的名单" << endl;
		for (vector<int>::iterator k = v2.begin(); k != v2.end(); ++k) {

			cout << "姓名： " << this->tester[*k].m_name << "编号："
				<< *k << "成绩： " << this->tester[*k].m_score[m_index - 1] << endl;
		}


	}
	else if (this->m_index == 2) {
		cout << "这是决赛的名单和成绩" << endl;
		for (vector<int>::iterator k = v3.begin(); k != v3.end(); ++k) {
			cout << "姓名： " << this->tester[*k].m_name << "编号："
				<< *k << "成绩： " << this->tester[*k].m_score[m_index - 1] << endl;
		}
	}
	

}

void Speechmanger::record() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator k = v3.begin(); k != v3.end(); ++k) {
		ofs << *k << "," << *tester[*k].m_score << ",";

	}
	ofs << endl;
	ofs.close();
	cout << "记录已经保存" << endl;
}

void Speechmanger::loadrecord() {
	ifstream ifs("speech.csv",ios::in);
	if (!ifs.is_open()) {
		this->fileempty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		this->fileempty = true;
		cout << "文件为空" << endl;
		ifs.close();
		return;
	}
	this->fileempty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	while (ifs>>data)
	{
		vector<string>vtem;
		int start = 0;
		int pos = -1;
		while(true){
			pos = data.find(",", start);
			if (pos == -1) {
				break;
			}		
			string tem = data.substr(start, pos-start);
			start = pos + 1;
			//cout << tem << endl;
			vtem.push_back(tem);
		}
		index++;
		this->m_record.insert(make_pair(index, vtem));
		vtem.clear();

	}
	ifs.close();

	for (map<int, vector<string>>::iterator k = m_record.begin(); k != m_record.end(); ++k) {
		cout << "第" << k->first << "届的成绩如下：" << endl;
		for (vector<string>::iterator k1 = k->second.begin(); k1 != k->second.end(); ++k1) {
			cout << *k1 << "  " ;
		}
		cout << endl;
	}



}

void Speechmanger::clean() {
	cout << "确认清空吗？" << endl;
	cout<<"1、确认清空" <<endl;
	cout<<"2、返回上一层"  <<endl;
	cout << "请输入你的选择" << endl;
	int sel = 0;
	cin >> sel;
	if (sel == 1) {
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		cout << "清空成功" << endl;
	}
	return;



}




void Speechmanger::kaishibisai() {
	//第一轮抽签
	chouqian();
	//第一轮比赛
	bisai();
	//打印晋级结果
	//第二轮抽签
	this->m_index++;
	chouqian();
	//第二轮比赛
	bisai();
	//打印结果
	//存储结果
	record();



}











