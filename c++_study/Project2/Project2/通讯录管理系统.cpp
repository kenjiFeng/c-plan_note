#include <iostream>
using namespace std;
#include <string>

struct lianxiren
{
	string name;
	int		age;
	string	sex;
	string		phone_unmber;
	int mark; //����Ƿ�Ϊ��
};
const int MAX=1000;
struct jiegouti {
	struct lianxiren lxrmax[MAX];
	int size;  //ͨѶ¼������
	
};
struct jiegouti aa;   //������1000���յĽṹ��Ԫ��

//�����˵�
void showmenu(){
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl; 
	cout << "0���˳�ͨѶ¼" << endl;
}


//��ӡ��������ϵ�˵�����
void listall() {
	for (int i = 0; i < 1000; i++)
	{
		if (i>=aa.size) {
			break;
		}
		cout << "��ϵ������: " << aa.lxrmax[i].name << "��ϵ������: " << aa.lxrmax[i].age << "��ϵ���Ա�: "
			<< aa.lxrmax[i].sex << "��ϵ�˵绰: " << aa.lxrmax[i].phone_unmber << endl;
		


	}
	cout << "��ϵ�˸���: " << aa.size<<endl;
}

//���ͨѶ¼�ĺ���
void addperson() {
	cout << "��������ϵ������" << endl;
	int i;
	if (aa.size == MAX)
	{
		cout << "��ͨѶ¼����" << endl;
		return;
	}
	for (i = 0; i < 1000; i++) {     //���ҳ���λ��
		if (i >= aa.size) {
			break;
		}
	}
	aa.lxrmax[i].mark = 1; //����������ϵ��
	cin >> aa.lxrmax[i].name;
	cout << "��������ϵ������" << endl;
	cin >> aa.lxrmax[i].age;
	cout << "��������ϵ���Ա�" << endl;
	cin >> aa.lxrmax[i].sex;
	cout << "��������ϵ�˵绰��" << endl;
	cin >> aa.lxrmax[i].phone_unmber;
	++aa.size;
	cout << "��ӳɹ�" << endl;
	system("pause");  //�밴���������
	system("cls");		//��������
	//showmenu();
}
//�����ϵ���Ƿ����
void deleteperson(jiegouti *p) {
	cout << "��������Ҫɾ������ϵ��" << endl;
	string a;
		cin >> a;
	for ( int i = 0; i < 1000;  i++)
	{
		if (a == p->lxrmax[i].name) {
			cout << "��ϵ������: " << aa.lxrmax[i].name << "��ϵ������: " << aa.lxrmax[i].age << "��ϵ���Ա�: "
				<< aa.lxrmax[i].sex << "��ϵ�˵绰: " << aa.lxrmax[i].phone_unmber << endl;
			cout << "����Ҫɾ������ϵ����" << endl;
			string bb;
			while (1)
			{
				cin >> bb;
				if (bb != "��" && bb != "��") 
				{
					cout << "�������ǻ����в���"<<endl;
					continue;
				}
				if (bb == "��")  //����ɾ����ϵ�˵Ĳ���
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
					
					cout << "ɾ���ɹ�" << endl;	
					cout << "���ص����˵�" << endl;
							
					return;
				}
				else { return; }
					
				
				
				
				
			}
		}
		if (i ==999&& a != p->lxrmax[i].name)
		{
			cout << "���޴���" << endl;
			break;	
		}

	}
	

}


//��ѯ��ϵ��
void findperson(jiegouti *p) {
	if (aa.size ==0)
	{
		cout << "�б�Ϊ�գ��������ϵ��" << endl;
		return;
	}
	cout << "��������Ҫ��ѯ����ϵ��" << endl;
	string a;
	cin >> a;
	for (int i = 0; i < 1000; i++)
	{
		if (a == p->lxrmax[i].name) {
			system("cls");
			cout << "��ϵ������: " << aa.lxrmax[i].name << "��ϵ������: " << aa.lxrmax[i].age << "��ϵ���Ա�: "
				<< aa.lxrmax[i].sex << "��ϵ�˵绰: " << aa.lxrmax[i].phone_unmber << endl;
			system("pause");
			return;
		}
		
		if (i ==999&& a != p->lxrmax[i].name)
		{
			cout << "���޴���" << endl;
			return;
		}
	}
	return;
}

//�޸���ϵ��
void updateperson(jiegouti *p) 
{
	if (aa.size == 0)
	{
		cout << "�б�Ϊ�գ��������ϵ��" << endl;
		return;
	}
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string a;
	cin >> a;
	for (int i = 0; i < 1000; i++)
	{
		if (a == p->lxrmax[i].name) {
			system("cls");
			cout << "��ϵ������: " << aa.lxrmax[i].name << "��ϵ������: " << aa.lxrmax[i].age << "��ϵ���Ա�: "
				<< aa.lxrmax[i].sex << "��ϵ�˵绰: " << aa.lxrmax[i].phone_unmber << endl;
			cout << "�Ƿ�ȷ���޸ĸ���ϵ�ˣ�" << endl;
			string bb;
			while (1)
			{
				cin >> bb;
				if (bb != "��" && bb != "��")
				{
					cout << "�������ǻ����в���" << endl;
					continue;
				}
				if (bb == "��")  //�����޸���ϵ�˵Ĳ���
				{
					cout << "�������µ���ϵ������" << endl;
					cin >> aa.lxrmax[i].name;
					cout << "�������µ���ϵ������" << endl;
					cin >> aa.lxrmax[i].age;
					cout << "�������µ���ϵ���Ա�" << endl;
					cin >> aa.lxrmax[i].sex;
					cout << "�������µ���ϵ�˵绰" << endl;
					cin >> aa.lxrmax[i].phone_unmber;
					cout << "�����ɹ�" << endl;
					system("pause");
					return;

				}



			}
			
		}

		if (i == 999 && a != p->lxrmax[i].name)
		{
			cout << "���޴���" << endl;
			return;
		}

	}

}

//�����ϵ��Ŀ¼
void deleteall01(jiegouti *p) {
	cout << "��ɾ������Ϊ�����棬�Ƿ�������У�" << endl;
	string aa;
	while (1)
	{
		cin >> aa;
		if (aa != "��" && aa != "��")
		{
			cout << "�������ǻ����в���" << endl;
			continue;
		}
		if (aa == "��")
		{
			memset(p->lxrmax, 0, sizeof(p->lxrmax));
			p->size = 0;
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			return;
		}
		return;
	}
}




	//ͨѶ¼�����˵�
int xuanze() {
	while (1)
	{
		int kk = 0;
		
		showmenu();
		cout << "�����빦��ǰ�İ���" << endl;
		cin >> kk;
		switch (kk)
		{
		case 1:
			addperson();
			break;		//�����ϵ��
		case 2:
			listall();
			break;		//��ʾ��ϵ��
		case 3:
			deleteperson(&aa);
			break;		//ɾ����ϵ��
		case 4:
			findperson(&aa);
			break;		//������ϵ��
		case 5:updateperson(&aa);
			break;		//�޸���ϵ��	
			
		case 6:
			deleteall01(&aa);
			break;		//�����ϵ��


		case 0:cout << "��ӭ�´�ʹ��" << endl;
			return 0;   //�˳�ͨ��¼
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