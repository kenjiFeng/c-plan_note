#include"empolyee.h"
#include<string>


empolyee::empolyee(int id, string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->m_depnum = did;
}
void empolyee::showall() {
	cout << "ְ����ţ�" << this->m_id << "\tְ��������" << this->m_name << "\t��λ" << this->getdepinf() <<
		"��λְ������Ա�������Ǵ���" << endl;
}
string empolyee::getdepinf() {
	return "Ա��";
}