#include"manager.h"
#include<string>


manager::manager(int id, string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->m_depnum = did;
}
void manager::showall() {
	cout << "ְ����ţ�" << this->m_id << "\tְ��������" << this->m_name << "\t��λ" << this->getdepinf()<<
		"��λְ�����Ǿ�����������������" << endl;
}
string manager::getdepinf() {
	return "����";
}