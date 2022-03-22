#include<iostream>
using namespace std;
#include"头文件管理.h"
#include<string>
#include<ctime>
void enter() {
	int choice = 0;
	
	while (1) {
		Speechmanger a;
		a.show_menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: //开始比赛
			a.kaishibisai();
			system("pause");
			a.showjinji();
			system("pause");
			system("cls");
			break;
		case 2:  //查看往届比赛记录
			a.loadrecord();
			break;
		case 3:		//清空比赛记录
			a.clean();
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
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



