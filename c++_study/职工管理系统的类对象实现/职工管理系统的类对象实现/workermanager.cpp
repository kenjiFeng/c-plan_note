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
		cout << "���ļ������� ������������ϵ��" << endl;
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
			if (ifs.eof())   //eofΪ�Ƿ��ȡ��������
			{
				cout << "���ļ����ڵ�Ϊ�� ������������ϵ��" << endl;
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
			cout << "��ְ������Ϊ" << num001 << "��" << endl;
			this->m_fileisempty = false;
			//��ʼ��ָ������
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
	ifs.open(FILENAME, ios::in);  //��ȡ�ļ�
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

		this->arr[index] = worker_gen;  //��ʼ���Ķ�������Ϊһ���б���������������
		index++;

	}
	ifs.close();
}



void worker::showmenu()
	{
		cout << "0���˳�����ϵͳ����" << endl;
		cout << "1������ְ��" << endl;
		cout << "2����ʾְ��" << endl;
		cout << "3��ɾ��ְ��" << endl;
		cout << "4���޸�ְ��" << endl;
		cout << "5������ְ��" << endl;
		cout << "6����������" << endl;
		cout << "7�����ְ��" << endl;
		cout << endl;


	}








void worker::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out); 
	//������ķ�ʽ���ļ� --д�ļ�
	
	for (int i = 0; i < this->m_EmpNum; ++i) {
		ofs << this->arr[i]->m_id << " "
			<< this->arr[i]->m_name << " "
			<< this->arr[i]->m_depnum << " " << endl;

	}
	ofs.close();
}




//��ȡ�ļ�
void worker::open() { 

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//ios::out ����д��
	//ios::in ���������//ios::ate ����Ӻ����
	////ios::app ��������µĲ���
	//ios::trunc ������ɾ����ǰ���ļ�����д��
	//��ȡ���ݣ�
	if (ifs.is_open()) {
		cout << "�򿪳ɹ�" << endl;
	}
	else
	{
		cout << "��ʧ��" << endl;
		return;
	}
	//��һ�ִ��ļ��ķ�ʽ
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








//����³�Ա����
void worker::add_num() {
	cout << "��������Ҫ��ӵ�����" << endl;
	int num;
	cin >> num;
	if (num != 0) {
		//��Ӳ���
		//�����¿ռ�Ĵ�С
		int newsize = this->m_EmpNum + num;
		worker_gen **newspace = new worker_gen*[newsize];   //�൱��һ����ά������
		//��������Ŀռ䲻Ϊ�գ�����ӵ��µ�������
		if (this->arr != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {  
				newspace[i] = this->arr[i];
			}
		}
		//�����µ�����
		for (int i = 0; i < num; ++i) {
			int id;
			string name;
			int dselect;

			cout << "�������" << i+1 << "����ְ�����" << endl;
			cin >> id;
			cout << "�������" << i+1 << "����ְ������" << endl;
			cin >> name;
			cout << "�������" << i+1<< "����ְ����λ���" << endl;
			cout << "1.Ա��  " << "2.����" << "3.�ϰ�" << endl;
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
		delete[] this->arr;  //�ͷ�ԭ���Ŀռ�
		this->arr = newspace;  //�����б�
	/*	delete[] newspace;
		*newspace = NULL;*/
		this->m_EmpNum = newsize;
		cout << "����ɹ����ɹ���ӳ�Ա" << endl;
		this->save();


	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");



}

void worker::showallmember() {
	/*if (this->arr==0) {
		cout << "����һ���ձ�����ӳ�Ա" << endl;
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
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);  //ֱ���˳���ǰ�ĳ���
}


worker::~worker(){
	delete this->arr;
	this->arr = NULL;

}



int worker::isexist(int a) {   //Ѱ�ҵ�ǰ�Ĵ���
	int b = -1;
	for (int i=0; i < this->m_EmpNum; ++i) {
		if (a == this->arr[i]->m_id) {
			b = i;
			break;
		}
	}
	return b;
}
//ɾ��Ա������
void worker::del_emp() {
	cout << "��������Ҫɾ����Ա�����" << endl;
	int aa1;
	cin >> aa1;
	if (this->isexist(aa1) == -1) {
		cout << "��Ա�������ڣ�����������" << endl;
		return;
	}
	else
	{
		int ret = this->isexist(aa1);
		for (int i = ret; i < this->m_EmpNum; ++i) {
			this->arr[i] = this->arr[i + 1];     //����������ɾָ�붼��Ҫ�ͷ�
		}
		int aa2 = --this->m_EmpNum;
		worker_gen **newspace = new worker_gen*[aa1];
		if (this->arr != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newspace[i] = this->arr[i];
			}
		}
		delete[] this->arr;  //�ͷ�ԭ���Ŀռ�
		this->arr = newspace;  //�����б�
		//this->m_EmpNum--;
		//delete[] newspace;
		cout << "ɾ���ɹ�" << endl;
		this->save(); //�����ļ�
	}
	system("pause");
	system("cls");
}

//�޸�Ա��
void worker::mod_emp() {
	if (this->m_EmpNum == 0) {
		cout << "����ļ��ǿյ�" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ�ְ�����" << endl;
		int aa;
		cin >> aa;
		int ret = this->isexist(aa);
		delete this->arr[ret];
		
		
		int id;
		string name;
		int dselect;

		cout << "��������ְ�����" << endl;
		cin >> id;
		cout << "��������ְ������" << endl;
		cin >> name;
		cout << "��������ְ����λ���" << endl;
		cout << "1.Ա��  " << "2.����" << "3.�ϰ�" << endl;
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
		cout << "�޸ĳɹ�" << endl;
	}
}


void worker::find_emp() {
	if (this->m_EmpNum == 0) {
		cout << "�ñ�Ϊ�գ�����ʧ��" << endl;
			return;
	}
	else
	{
		cout << "��������Ҫ���ҵ�Ա�����" << endl;
		int aa;
		cin >> aa;
		int ret = this->isexist(aa);
		if (ret ==-1)
		{
			cout << "û�и�Ա��" << endl;
			return;
		}
		else
		{
			this->arr[ret]->showall();
			cout << "���ҳɹ�" << endl;
			return;
		}
	}
}

void worker::soft_emp() {
	if (this->m_fileisempty == true) {
		cout << "���ļ�Ϊ�գ��޷�����" << endl;
		return;
	}
	else
	{
		cout << "��ѡ������ķ���" << endl;
		cout << "1������Ա��ID������������" << endl;
		cout << "2������Ա��ID���н�������" << endl;
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
		cout << "����ɹ�" << endl;
		this->save();
		this->showallmember();

	}
}



void worker::clear_all() {
	cout << "�Ƿ�ɾ�����е����ݣ�" << endl;
	cout << "1��ȷ��ɾ��" << endl;
	cout << "2��������һ��" << endl;
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
	cout << "��ճɹ�" << endl;
}