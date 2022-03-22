#include"boss.h"
#include<string>


boss::boss(int id, string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->m_depnum = did;
}
void boss::showall() {
	cout << "职工编号：" << this->m_id << "\t职工姓名：" << this->m_name << "\t岗位" << this->getdepinf()<<
		"岗位职责：我是老板，做老板的事"<<endl;
}
string boss::getdepinf() {
	return "老板";
}