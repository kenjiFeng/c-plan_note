#pragma once 
#include<string>
#include<iostream>
using namespace std;


template<class T>
class arra {
public:
	arra(int cap) {   //��ʼ���캯��
		cout << "Ĭ���вι���" << endl;
		this->arr = new T[cap];
		this->m_size = 0;
		this->m_capacity = cap;

	}
	//��������
	arra(const arra &a) {
		cout << "��������" << endl;
		this->m_size = a.m_size;
		this->m_capacity = a.m_capacity;
		this->arr = new T[this->m_capacity];
		for (int i=0; i < this->m_capacity; ++i) {
			this->arr[i] = a.arr[i];
		}
	}
	//operator =
	arra& operator=(const arra &a) {  //�����ŵ�Ŀ��������������  ��a =b =c
		cout << "�ȺŹ���" << endl;
		this->m_size = a.m_size;
		this->m_capacity = a.m_capacity;
		if (this->arr != NULL) {
			delete[] this->arr;
			this->arr = NULL;
		}
		for (int i; i < this->m_capacity; ++i) {
			this->arr[i] = a.arr[i];
		}
		return *this;
	}

	void push_in(const T &val) {   //β���Ԫ��
		if (this->m_size == this->m_capacity) {
			return;
		}
		this->arr[this->m_size] = val;
		this->m_size++;
	}

	arra operator[](int index) {
		return this->arr[index];
	}

	void pop_out() {   //βɾ
		if (this->m_size == 0) {
			return;
						
		}
		this->m_size--;
	}

	~arra()
	{

		cout << "��������" << endl;
		if (this->arr !=NULL) {
			delete[] this->arr;
			this->arr = NULL;
		}
	}






	int m_size;
	int m_capacity;
	T * arr;
};