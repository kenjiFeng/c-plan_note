#include"workmanager.h"
#include<string>
using namespace std;
#include"empolyee.h"
#include"boss.h"
#include"manager.h"



worker::worker() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{	
		cout << "该文件不存在 请重新输入联系人" << endl;
		this->m_EmpNum = 0;
		this->arr = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	else
	{
		int id;
		int did;
		string aa;
		int num001 =0;
		while (ifs>>id&&ifs>>aa&&ifs>>did)
		{
			num001++;
		}
		if (num001 == 0) {
			char ch;
			ifs >> ch;
			if (ifs.eof())   //eof为是否读取最后的数据
			{
				cout << "该文件存在但为空 请重新输入联系人" << endl;
				this->m_EmpNum = 0;
				this->arr = NULL;
				this->m_fileisempty = true;
				ifs.close();
				system("pause");
				return;

			}
		}
		else
		{
			this->m_EmpNum = num001;
			cout << "该职工人数为" << num001 << "个" << endl;
			this->m_fileisempty = false;
			//初始化指针数组
			this->arr = new worker_gen*[num001];
			this->m_arr();
			/*for (int i = 0; i < num001; i++)
			{
				cout << this->arr[i]->m_id;
				cout << this->arr[i]->m_name;
				cout << this->arr[i]->m_depnum;
			}*/
			ifs.close();
			
			return;
		}
	}

}

void worker::m_arr() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //读取文件
	int id;
	int did;
	string aa;
	int index = 0;
	while (ifs >> id && ifs >> aa && ifs >> did)
	{
		worker_gen *worker_gen = NULL;
		if (did == 1) {
			worker_gen = new empolyee(id, aa, did);
		}
		if (did == 2) {
			worker_gen = new manager(id, aa, did);
		}
		if (did == 3) {
			worker_gen = new boss(id, aa, did);
		}

		this->arr[index] = worker_gen;  //初始化的对象数组为一个列表，可以自由组合添加
		index++;

	}
	ifs.close();
}



void worker::showmenu()
	{
		cout << "0、退出管理系统程序" << endl;
		cout << "1、增加职工" << endl;
		cout << "2、显示职工" << endl;
		cout << "3、删除职工" << endl;
		cout << "4、修改职工" << endl;
		cout << "5、查找职工" << endl;
		cout << "6、按编排序" << endl;
		cout << "7、清空职工" << endl;
		cout << endl;


	}








void worker::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out); 
	//用输入的方式打开文件 --写文件
	
	for (int i = 0; i < this->m_EmpNum; ++i) {
		ofs << this->arr[i]->m_id << " "
			<< this->arr[i]->m_name << " "
			<< this->arr[i]->m_depnum << " " << endl;

	}
	ofs.close();
}




//读取文件
void worker::open() { 

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//ios::out 代表写入
	//ios::in 代表读数据//ios::ate 代表从后面读
	////ios::app 代表添加新的材料
	//ios::trunc 代表是删除当前的文件重新写入
	//读取数据；
	if (ifs.is_open()) {
		cout << "打开成功" << endl;
	}
	else
	{
		cout << "打开失败" << endl;
		return;
	}
	//第一种打开文件的方式
	char aa[10000] = { 0 };
	/*while (ifs>>aa)
	{
		cout << aa << endl;
	}
	ifs.close();*/
	system("cls");
	
	while (ifs.getline(aa, 1024))
	{
		cout << aa << endl;
	}
	ifs.close();
	system("pause");
}








//添加新成员函数
void worker::add_num() {
	cout << "请输入需要添加的人数" << endl;
	int num;
	cin >> num;
	if (num != 0) {
		//添加操作
		//计算新空间的大小
		int newsize = this->m_EmpNum + num;
		worker_gen **newspace = new worker_gen*[newsize];   //相当于一个二维的数组
		//如果本来的空间不为空，则添加到新的数组中
		if (this->arr != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {  
				newspace[i] = this->arr[i];
			}
		}
		//输入新的数据
		for (int i = 0; i < num; ++i) {
			int id;
			string name;
			int dselect;

			cout << "请输入第" << i+1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i+1 << "个新职工姓名" << endl;
			cin >> name;
			cout << "请输入第" << i+1<< "个新职工岗位编号" << endl;
			cout << "1.员工  " << "2.经理" << "3.老板" << endl;
			cin >> dselect;

			worker_gen	*worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new empolyee(id, name, 3);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 1);
				break;
			default:
				break;
			}
			newspace[this->m_EmpNum + i] = worker;


		}
		delete[] this->arr;  //释放原来的空间
		this->arr = newspace;  //更新列表
	/*	delete[] newspace;
		*newspace = NULL;*/
		this->m_EmpNum = newsize;
		cout << "输入成功，成功添加成员" << endl;
		this->save();


	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");



}

void worker::showallmember() {
	/*if (this->arr==0) {
		cout << "这是一个空表，请添加成员" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; ++i) {
			this->arr[i]->showall();
		}
	}*/
	this->open();
}




void worker::exitsystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);  //直接退出当前的程序
}


worker::~worker(){
	delete this->arr;
	this->arr = NULL;

}



int worker::isexist(int a) {   //寻找当前的代号
	int b = -1;
	for (int i=0; i < this->m_EmpNum; ++i) {
		if (a == this->arr[i]->m_id) {
			b = i;
			break;
		}
	}
	return b;
}
//删除员工操作
void worker::del_emp() {
	cout << "请输入需要删除的员工编号" << endl;
	int aa1;
	cin >> aa1;
	if (this->isexist(aa1) == -1) {
		cout << "该员工不存在，请重新输入" << endl;
		return;
	}
	else
	{
		int ret = this->isexist(aa1);
		for (int i = ret; i < this->m_EmpNum; ++i) {
			this->arr[i] = this->arr[i + 1];     //单反动过增删指针都需要释放
		}
		int aa2 = --this->m_EmpNum;
		worker_gen **newspace = new worker_gen*[aa1];
		if (this->arr != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newspace[i] = this->arr[i];
			}
		}
		delete[] this->arr;  //释放原来的空间
		this->arr = newspace;  //更新列表
		//this->m_EmpNum--;
		//delete[] newspace;
		cout << "删除成功" << endl;
		this->save(); //保存文件
	}
	system("pause");
	system("cls");
}

//修改员工
void worker::mod_emp() {
	if (this->m_EmpNum == 0) {
		cout << "这个文件是空的" << endl;
	}
	else
	{
		cout << "请输入需要修改的职工编号" << endl;
		int aa;
		cin >> aa;
		int ret = this->isexist(aa);
		delete this->arr[ret];
		
		
		int id;
		string name;
		int dselect;

		cout << "请输入新职工编号" << endl;
		cin >> id;
		cout << "请输入新职工姓名" << endl;
		cin >> name;
		cout << "请输入新职工岗位编号" << endl;
		cout << "1.员工  " << "2.经理" << "3.老板" << endl;
		cin >> dselect;

		worker_gen	*worker = NULL;
		switch (dselect)
		{
		case 1:
			worker = new empolyee(id, name, 3);
			break;
		case 2:
			worker = new manager(id, name, 2);
			break;
		case 3:
			worker = new boss(id, name, 1);
			break;
		default:
			break;
		}
		this->arr[ret] = worker;
		this->save();
		cout << "修改成功" << endl;
	}
}


void worker::find_emp() {
	if (this->m_EmpNum == 0) {
		cout << "该表为空，查找失败" << endl;
			return;
	}
	else
	{
		cout << "请输入需要查找的员工编号" << endl;
		int aa;
		cin >> aa;
		int ret = this->isexist(aa);
		if (ret ==-1)
		{
			cout << "没有该员工" << endl;
			return;
		}
		else
		{
			this->arr[ret]->showall();
			cout << "查找成功" << endl;
			return;
		}
	}
}

void worker::soft_emp() {
	if (this->m_fileisempty == true) {
		cout << "该文件为空，无法排序" << endl;
		return;
	}
	else
	{
		cout << "请选择排序的方法" << endl;
		cout << "1、按照员工ID进行升序排序" << endl;
		cout << "2、按照员工ID进行降序排序" << endl;
		int aa;
		cin >> aa;
		if (aa == 1) {
			for (int i = 0; i < this->m_EmpNum; ++i) {
				int  minormax =i;
				for (int j = i + 1; j < this->m_EmpNum; ++j) {
					if (this->arr[j]->m_id < this->arr[minormax]->m_id) {
						minormax = j;
					}
				}
				if (i != minormax) {
					worker_gen *work = this->arr[i];
					this->arr[i] = this->arr[minormax];
					this->arr[minormax] = work;

				}
			}
		}
		if (aa == 2) {
			for (int i = 0; i < this->m_EmpNum; ++i) {
				int  minormax = i;
				for (int j = i + 1; j < this->m_EmpNum; ++j) {
					if (this->arr[j]->m_id > this->arr[minormax]->m_id) {
						minormax = j;
					}
				}
				if (i != minormax) {
					worker_gen *work = this->arr[i];
					this->arr[i] = this->arr[minormax];
					this->arr[minormax] = work;

				}
			}
		}
		cout << "排序成功" << endl;
		this->save();
		this->showallmember();

	}
}



void worker::clear_all() {
	cout << "是否删除所有的数据？" << endl;
	cout << "1、确认删除" << endl;
	cout << "2、返回上一层" << endl;
	int aa;
	cin >> aa;
	if (aa == 1) {
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();
		for (int i = 0; i < this->m_EmpNum; ++i) {
			delete this->arr[i];
		}
		this->m_fileisempty = true;
		this->m_EmpNum = 0;
		delete []this->arr;
		this->arr = NULL;
	}
	if (aa == 2) {
		return;
	}
	cout << "清空成功" << endl;
}