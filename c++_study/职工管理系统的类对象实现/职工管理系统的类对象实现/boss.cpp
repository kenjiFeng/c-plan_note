#include"boss.h"
#include<string>


boss::boss(int id, string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->m_depnum = did;
}
void boss::showall() {
	cout << "ְ����ţ�" << this->m_id << "\tְ��������" << this->m_name << "\t��λ" << this->getdepinf()<<
		"��λְ�������ϰ壬���ϰ����"<<endl;
}
string boss::getdepinf() {
	return "�ϰ�";
}