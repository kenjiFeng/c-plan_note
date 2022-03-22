#include<iostream>
#include<stdio.h>
#include"ͷ�ļ�����.h"
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
		string name_sed = "ѡ��";
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
	cout << "��ӭ��Ҳμӱ����ݽ�����" << endl;
	cout << "1����ʼ�ݽ�����" << endl;
	cout << "2���鿴���������¼" << endl;
	cout << "3�����������¼" << endl;
	cout << "0���˳���������" << endl;
	cout << endl;
}

void Speechmanger::chouqian() {
	cout << "��ʼ��ǩ��" << endl;
	if (m_index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		cout << "��һ�ֳ�ǩ������£�" << endl;
		for (vector<int>::iterator k = v1.begin(); k != v1.end();
			++k) {
			cout << *k<<"  ";
		}
		system("pause");

	}
	else if(m_index == 2)
	{
		random_shuffle(v2.begin(), v2.end());
		cout << "�ڶ��ֳ�ǩ������£�" << endl;
		for (vector<int>::iterator k = v2.begin(); k != v2.end();
			++k) {
			cout << *k << "  ";
		}
		system("pause");
	}
}

void Speechmanger::bisai() {
	cout << "��ʼ������" << endl;
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
			cout << "��" << num / 6 << "��" << "����" << endl;
			for (multimap<double, int, greater<double>>::iterator k = contain.begin(); k != contain.end(); ++k) {
				cout << "������ " << this->tester[k->second].m_name <<"��ţ�"
					<<k->second << "�ɼ��� " << this->tester[k->second].m_score[m_index - 1] << endl;
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
		cout << "���ǽ�����������" << endl;
		for (vector<int>::iterator k = v2.begin(); k != v2.end(); ++k) {

			cout << "������ " << this->tester[*k].m_name << "��ţ�"
				<< *k << "�ɼ��� " << this->tester[*k].m_score[m_index - 1] << endl;
		}


	}
	else if (this->m_index == 2) {
		cout << "���Ǿ����������ͳɼ�" << endl;
		for (vector<int>::iterator k = v3.begin(); k != v3.end(); ++k) {
			cout << "������ " << this->tester[*k].m_name << "��ţ�"
				<< *k << "�ɼ��� " << this->tester[*k].m_score[m_index - 1] << endl;
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
	cout << "��¼�Ѿ�����" << endl;
}

void Speechmanger::loadrecord() {
	ifstream ifs("speech.csv",ios::in);
	if (!ifs.is_open()) {
		this->fileempty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//�ļ�������
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		this->fileempty = true;
		cout << "�ļ�Ϊ��" << endl;
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
		cout << "��" << k->first << "��ĳɼ����£�" << endl;
		for (vector<string>::iterator k1 = k->second.begin(); k1 != k->second.end(); ++k1) {
			cout << *k1 << "  " ;
		}
		cout << endl;
	}



}

void Speechmanger::clean() {
	cout << "ȷ�������" << endl;
	cout<<"1��ȷ�����" <<endl;
	cout<<"2��������һ��"  <<endl;
	cout << "���������ѡ��" << endl;
	int sel = 0;
	cin >> sel;
	if (sel == 1) {
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		cout << "��ճɹ�" << endl;
	}
	return;



}




void Speechmanger::kaishibisai() {
	//��һ�ֳ�ǩ
	chouqian();
	//��һ�ֱ���
	bisai();
	//��ӡ�������
	//�ڶ��ֳ�ǩ
	this->m_index++;
	chouqian();
	//�ڶ��ֱ���
	bisai();
	//��ӡ���
	//�洢���
	record();



}











