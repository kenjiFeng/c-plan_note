#pragma once
#include <iostream>
using namespace std;
#include <string>

#include"worker_gen.h" 

class manager:public worker_gen {
public:
	manager(int id, string name, int did);
	virtual void showall();
	virtual string getdepinf();
};