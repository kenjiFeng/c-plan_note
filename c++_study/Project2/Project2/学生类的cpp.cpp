#include "ѧ����ͷ�ļ�.h"

//��ʾ������ѧ�ŵĺ���
void	student::lista() {
	cout << "����Ϊ�� " << name << endl;
	cout << "ѧ��Ϊ�� " << s_ID << endl;
	cout << "�ɼ�Ϊ�� " << chengji << endl;

}
void student::setchengji(int a) {
	chengji = a;
}
int student::getchengji() {
	return	chengji;
}

//��Ա�����ж��Ƿ������ɼ����
bool student::issame(student &a) {
	if (getchengji() == a.getchengji())
	{
		return true;
	}
}
