#pragma once
#include <iostream>
using namespace std;
#include <string>
#include"worker_gen.h" 

class boss:public worker_gen {
public:
	boss(int id,string name,int did);
	virtual void showall() ;
	virtual string getdepinf() ;
};