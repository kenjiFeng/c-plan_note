#include <iostream>
using namespace std;
#include "workmanager.h"
#include"boss.h"
#include"worker_gen.h"
#include"empolyee.h"
#include"manager.h"




void entrance() {
	worker aa;
	int choice;






	while (1) {
		aa.showmenu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		
		switch (choice)
		{
		case 0: 
			//cout << "��ӭ�´�ʹ��" << endl;
			aa.exitsystem();
			break;
		case 1: //���Ա��
			aa.add_num();
			break; 
		case 2:  //��ʾ����Ա��
			aa.showallmember();
			break; 
		case 3:  //ɾ��Ա��
			aa.del_emp();
			break; 
		case 4:  //�޸�Ա������
			aa.mod_emp();
			break; 
		case 5:  //����Ա��
			aa.find_emp();
			break;
		case 6:  //����������
			aa.soft_emp();
			break;
		case 7:  //���Ա��
			aa.clear_all();
			break;
		default:
			system("cls");
			break;
		}
	}
}




int main() {
	entrance();

	system("pause");
	return 0;
}