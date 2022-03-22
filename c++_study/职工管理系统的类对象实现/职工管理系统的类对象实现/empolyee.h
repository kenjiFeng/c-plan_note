#pragma once
#include <iostream>
using namespace std;
#include"worker_gen.h" 
#include <string>

class empolyee :public worker_gen {
public:
	empolyee(int id, string name, int did);
	void showall();
	string getdepinf();
};