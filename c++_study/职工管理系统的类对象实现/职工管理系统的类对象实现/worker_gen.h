#pragma once
#include <iostream>
using namespace std;
#include <string>


//��Ϊһ������Ļ���

class worker_gen {
public:
	virtual void showall() = 0;
	virtual string getdepinf() = 0;
	int m_id;
	int m_depnum;
	string m_name;
};