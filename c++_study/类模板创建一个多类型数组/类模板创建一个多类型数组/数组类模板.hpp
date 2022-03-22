#pragma once 
#include<string>
#include<iostream>
using namespace std;


template<class T>
class arra {
public:
	arra(int cap) {   //初始构造函数
		cout << "默认有参构造" << endl;
		this->arr = new T[cap];
		this->m_size = 0;
		this->m_capacity = cap;

	}
	//拷贝构造
	arra(const arra &a) {
		cout << "拷贝构造" << endl;
		this->m_size = a.m_size;
		this->m_capacity = a.m_capacity;
		this->arr = new T[this->m_capacity];
		for (int i=0; i < this->m_capacity; ++i) {
			this->arr[i] = a.arr[i];
		}
	}
	//operator =
	arra& operator=(const arra &a) {  //加引号的目的在于连续操作  如a =b =c
		cout << "等号构造" << endl;
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

	void push_in(const T &val) {   //尾插加元素
		if (this->m_size == this->m_capacity) {
			return;
		}
		this->arr[this->m_size] = val;
		this->m_size++;
	}

	arra operator[](int index) {
		return this->arr[index];
	}

	void pop_out() {   //尾删
		if (this->m_size == 0) {
			return;
						
		}
		this->m_size--;
	}

	~arra()
	{

		cout << "析构构造" << endl;
		if (this->arr !=NULL) {
			delete[] this->arr;
			this->arr = NULL;
		}
	}






	int m_size;
	int m_capacity;
	T * arr;
};