#include"empolyee.h"
#include<string>


empolyee::empolyee(int id, string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->m_depnum = did;
}
void empolyee::showall() {
	cout << "职工编号：" << this->m_id << "\t职工姓名：" << this->m_name << "\t岗位" << this->getdepinf() <<
		"岗位职责：我是员工，我是打工人" << endl;
}
string empolyee::getdepinf() {
	return "员工";
}