#pragma once
#include <iostream>
using namespace std;
#include <string>
#include"worker_gen.h"
#include<fstream>
#define FILENAME "empty.txt"



class worker {
public:
	worker();

	void showmenu();
	void exitsystem();
	void save();  //���ִ���
	void open();
	void showallmember();
	void add_num();
	void m_arr(); //���ļ����ϣ���ʼ������
	void del_emp();
	int isexist(int);
	void mod_emp();
	void find_emp();
	void soft_emp();
	void clear_all();



	int m_num;
	int m_EmpNum;
	worker_gen **arr;
	bool m_fileisempty;
	/*virtual void showallinf() =0;
	virtual void showinfaboutdep() =0;*/
	//int m_ID;
	//int m_dep_num;
	//string m_name;
	~worker();
};