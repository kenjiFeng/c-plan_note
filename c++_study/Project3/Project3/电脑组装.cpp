//#include<iostream>
//using namespace std;
//#include<string>
//	
//class cpu
//{
//public:
//	virtual void calculate()=0;
//	//����cpu
//};
//class gpu
//{
//public:
//	virtual void display() = 0;
//	//����gpu
//};
//class memory
//{
//public:
//	virtual void storage() = 0;
//	//�����ڴ�
//};
//
//class computer {
//public:
//	computer(gpu*gpu,cpu*cpu,memory*memory) {
//		m_gpu = gpu;
//		m_cpu = cpu;
//		m_memory = memory;
//
//	}
//	gpu *m_gpu;
//	cpu *m_cpu;
//	memory *m_memory;
//	~computer() {
//		if (m_cpu != NULL) {
//			delete  m_cpu;
//			m_cpu = NULL;
//			cout << "�ɹ�����" << endl;
//		}
//		if (m_gpu != NULL) {
//			delete  m_gpu;
//			m_gpu = NULL;
//			cout << "�ɹ�����" << endl;
//		}
//		if (m_memory != NULL) {
//			delete  m_memory;
//			m_memory = NULL;
//			cout << "�ɹ�����" << endl;
//		}
//		cout << "chengg" << endl;
//	}
//	void work() {
//		m_gpu->display();
//		m_cpu->calculate();
//		m_memory->storage();
//
//	}
//};
//class intelcpu :public cpu
//{public:
//	void calculate() {
//		cout << "intelcpu now calculating" << endl;
//	}
//
//};
//class intelgpu :public gpu
//{
//public:
//	void display() {
//		cout << "intelgpu now calculating" << endl;
//	}
//
//};
//
//class intelmemory :public memory
//{
//public:
//	void storage() {
//		cout << "intelmemory now calculating" << endl;
//	}
//
//};
//
//void test() {
//	computer s1(new intelgpu, new intelcpu, new intelmemory);
//	s1.work();
//}
//
//int main() {
//	test();
//}