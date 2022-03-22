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
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		
		switch (choice)
		{
		case 0: 
			//cout << "欢迎下次使用" << endl;
			aa.exitsystem();
			break;
		case 1: //添加员工
			aa.add_num();
			break; 
		case 2:  //显示所有员工
			aa.showallmember();
			break; 
		case 3:  //删除员工
			aa.del_emp();
			break; 
		case 4:  //修改员工资料
			aa.mod_emp();
			break; 
		case 5:  //查找员工
			aa.find_emp();
			break;
		case 6:  //按编码排序
			aa.soft_emp();
			break;
		case 7:  //清空员工
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