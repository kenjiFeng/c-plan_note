#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>


class speaker {
public:
	string m_name;
	double m_score[2];

};




class Speechmanger {
public:
	Speechmanger();


	~Speechmanger();

	void show_menu();

	void initSpeech();

	void creat_speaker();

	void chouqian();

	void kaishibisai();

	void bisai();

	void record();

	void showjinji();

	void loadrecord();

	void clean();





	bool fileempty;

	map<int, vector<string>>m_record;

	vector<int> v1;  //��һ�α������� 12
	vector<int> v2;		//��2�α������� 6 
	vector<int> v3;		//��2�α�������  3


	map<int, speaker> tester;

	int m_index;


};















