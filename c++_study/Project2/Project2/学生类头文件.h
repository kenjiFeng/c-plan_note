#pragma once
#include <iostream>	
using namespace std;
#include	<string>
//�����ͷ�ļ�����������Ҫд���о��庯����ֻ��Ҫд����
//��Դ�ļ�����Ҳ��Ҫ��Ӹ�ͷ�ļ����ܹ�ʹ��
//��Դ�ļ���ֻҪ��Ӹ����ͷ�ļ���д�ú������ʽ����ʹ��

class student
{
public:
	string name;
	int s_ID;
	//��ʾ������ѧ�ŵĺ���
	void lista();
	void setchengji(int a);
	int getchengji();

	//��Ա�����ж��Ƿ������ɼ����
	bool issame(student &a);


private:
	int chengji;
};

