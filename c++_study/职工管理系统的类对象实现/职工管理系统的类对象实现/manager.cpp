#include"manager.h"
#include<string>


manager::manager(int id, string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->m_depnum = did;
}
void manager::showall() {
	cout << "职工编号：" << this->m_id << "\t职工姓名：" << this->m_name << "\t岗位" << this->getdepinf()<<
		"岗位职责：我是经理，我做经理做的事" << endl;
}
string manager::getdepinf() {
	return "经理";
}