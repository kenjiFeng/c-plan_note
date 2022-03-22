#include <iostream>
using namespace std;
#include <string>

struct lianxiren
{
	string name;
	int		age;
	string	sex;
	string		phone_unmber;
	int mark; //检测是否为空
};
const int MAX=1000;
struct jiegouti {
	struct lianxiren lxrmax[MAX];
	int size;  //通讯录的人数
	
};
struct jiegouti aa;   //创建了1000个空的结构体元组

//创建菜单
void showmenu(){
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl; 
	cout << "0、退出通讯录" << endl;
}


//打印出各个联系人的名单
void listall() {
	for (int i = 0; i < 1000; i++)
	{
		if (i>=aa.size) {
			break;
		}
		cout << "联系人姓名: " << aa.lxrmax[i].name << "联系人年龄: " << aa.lxrmax[i].age << "联系人性别: "
			<< aa.lxrmax[i].sex << "联系人电话: " << aa.lxrmax[i].phone_unmber << endl;
		


	}
	cout << "联系人个数: " << aa.size<<endl;
}

//添加通讯录的函数
void addperson() {
	cout << "请输入联系人姓名" << endl;
	int i;
	if (aa.size == MAX)
	{
		cout << "该通讯录已满" << endl;
		return;
	}
	for (i = 0; i < 1000; i++) {     //查找出空位置
		if (i >= aa.size) {
			break;
		}
	}
	aa.lxrmax[i].mark = 1; //代表已有联系人
	cin >> aa.lxrmax[i].name;
	cout << "请输入联系人年龄" << endl;
	cin >> aa.lxrmax[i].age;
	cout << "请输入联系人性别" << endl;
	cin >> aa.lxrmax[i].sex;
	cout << "请输入联系人电话号" << endl;
	cin >> aa.lxrmax[i].phone_unmber;
	++aa.size;
	cout << "添加成功" << endl;
	system("pause");  //请按任意键结束
	system("cls");		//清屏操作
	//showmenu();
}
//检测联系人是否存在
void deleteperson(jiegouti *p) {
	cout << "请输入需要删除的联系人" << endl;
	string a;
		cin >> a;
	for ( int i = 0; i < 1000;  i++)
	{
		if (a == p->lxrmax[i].name) {
			cout << "联系人姓名: " << aa.lxrmax[i].name << "联系人年龄: " << aa.lxrmax[i].age << "联系人性别: "
				<< aa.lxrmax[i].sex << "联系人电话: " << aa.lxrmax[i].phone_unmber << endl;
			cout << "你需要删除该联系人吗？" << endl;
			string bb;
			while (1)
			{
				cin >> bb;
				if (bb != "是" && bb != "否") 
				{
					cout << "请输入是或否进行操作"<<endl;
					continue;
				}
				if (bb == "是")  //进行删除联系人的操作
				{
					for (int j = i; j < aa.size + 1; j++)
					{
						p->lxrmax[j].age = p->lxrmax[j + 1].age;
						p->lxrmax[j].name = p->lxrmax[j + 1].name;
						p->lxrmax[j].mark = p->lxrmax[j + 1].mark;
						p->lxrmax[j].sex = p->lxrmax[j + 1].sex;
						p->lxrmax[j].phone_unmber = p->lxrmax[j + 1].phone_unmber;
					}
					aa.size--;
					system("pause");
					system("cls");
					
					cout << "删除成功" << endl;	
					cout << "返回到主菜单" << endl;
							
					return;
				}
				else { return; }
					
				
				
				
				
			}
		}
		if (i ==999&& a != p->lxrmax[i].name)
		{
			cout << "查无此人" << endl;
			break;	
		}

	}
	

}


//查询联系人
void findperson(jiegouti *p) {
	if (aa.size ==0)
	{
		cout << "列表为空，请添加联系人" << endl;
		return;
	}
	cout << "请输入需要查询的联系人" << endl;
	string a;
	cin >> a;
	for (int i = 0; i < 1000; i++)
	{
		if (a == p->lxrmax[i].name) {
			system("cls");
			cout << "联系人姓名: " << aa.lxrmax[i].name << "联系人年龄: " << aa.lxrmax[i].age << "联系人性别: "
				<< aa.lxrmax[i].sex << "联系人电话: " << aa.lxrmax[i].phone_unmber << endl;
			system("pause");
			return;
		}
		
		if (i ==999&& a != p->lxrmax[i].name)
		{
			cout << "查无此人" << endl;
			return;
		}
	}
	return;
}

//修改联系人
void updateperson(jiegouti *p) 
{
	if (aa.size == 0)
	{
		cout << "列表为空，请添加联系人" << endl;
		return;
	}
	cout << "请输入需要修改的联系人" << endl;
	string a;
	cin >> a;
	for (int i = 0; i < 1000; i++)
	{
		if (a == p->lxrmax[i].name) {
			system("cls");
			cout << "联系人姓名: " << aa.lxrmax[i].name << "联系人年龄: " << aa.lxrmax[i].age << "联系人性别: "
				<< aa.lxrmax[i].sex << "联系人电话: " << aa.lxrmax[i].phone_unmber << endl;
			cout << "是否确定修改该联系人？" << endl;
			string bb;
			while (1)
			{
				cin >> bb;
				if (bb != "是" && bb != "否")
				{
					cout << "请输入是或否进行操作" << endl;
					continue;
				}
				if (bb == "是")  //进行修改联系人的操作
				{
					cout << "请输入新的联系人姓名" << endl;
					cin >> aa.lxrmax[i].name;
					cout << "请输入新的联系人年龄" << endl;
					cin >> aa.lxrmax[i].age;
					cout << "请输入新的联系人性别" << endl;
					cin >> aa.lxrmax[i].sex;
					cout << "请输入新的联系人电话" << endl;
					cin >> aa.lxrmax[i].phone_unmber;
					cout << "操作成功" << endl;
					system("pause");
					return;

				}



			}
			
		}

		if (i == 999 && a != p->lxrmax[i].name)
		{
			cout << "查无此人" << endl;
			return;
		}

	}

}

//清空联系人目录
void deleteall01(jiegouti *p) {
	cout << "该删除操作为不可逆，是否继续进行？" << endl;
	string aa;
	while (1)
	{
		cin >> aa;
		if (aa != "是" && aa != "否")
		{
			cout << "请输入是或否进行操作" << endl;
			continue;
		}
		if (aa == "是")
		{
			memset(p->lxrmax, 0, sizeof(p->lxrmax));
			p->size = 0;
			cout << "删除成功" << endl;
		}
		else
		{
			return;
		}
		return;
	}
}




	//通讯录的主菜单
int xuanze() {
	while (1)
	{
		int kk = 0;
		
		showmenu();
		cout << "请输入功能前的按键" << endl;
		cin >> kk;
		switch (kk)
		{
		case 1:
			addperson();
			break;		//添加联系人
		case 2:
			listall();
			break;		//显示联系人
		case 3:
			deleteperson(&aa);
			break;		//删除联系人
		case 4:
			findperson(&aa);
			break;		//查找联系人
		case 5:updateperson(&aa);
			break;		//修改联系人	
			
		case 6:
			deleteall01(&aa);
			break;		//清空联系人


		case 0:cout << "欢迎下次使用" << endl;
			return 0;   //退出通信录
			break;
		default:
			break;
		}

	}


}

//int main() {
	//aa.size = 0;
	//xuanze();
//}