#include<iostream>
using namespace std;
#include"ͷ�ļ�����.h"
#include<string>
#include<ctime>
void enter() {
	int choice = 0;
	
	while (1) {
		Speechmanger a;
		a.show_menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: //��ʼ����
			a.kaishibisai();
			system("pause");
			a.showjinji();
			system("pause");
			system("cls");
			break;
		case 2:  //�鿴���������¼
			a.loadrecord();
			break;
		case 3:		//��ձ�����¼
			a.clean();
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			return ;
			break;

		default:
			system("cls");
			break;
		}




	}



}












int main() {

	srand(time(NULL));
	enter();



	system("pause");
	return 0;
}



