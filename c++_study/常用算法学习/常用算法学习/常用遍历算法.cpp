#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//�����º���
class fanghanshu {
public:
	void operator()(int v1) {
		cout<< v1;
	}

};
class fanghanshu1 {
public:
	int operator()(int a) {
		return a;
	}
};

void test() {
	vector<int> v;
	for (int i =0; i < 5; ++i) {
		v.push_back(i);
	}
	vector<int> v1;
	v1.resize(v.size());
	//����1:tranform
	transform(v.begin(), v.end(), v1.begin(), fanghanshu1());
	//����2:for_each
	for_each(v.begin(), v.end(), fanghanshu());
	for (vector<int> ::iterator k = v1.begin(); k != v1.end(); k++) {
		cout << *k << endl;
	}
	//���ò����㷨
	//find_if(begin\end\ν��)
	//count_if(begin\end\ν��)
	//adjacent_find ���������ظ�Ԫ��
	//binary_find ���ֲ�������,���Ƿ���ֵ������߼�  ǰ�������������
	//random_shuffle(begin,end
	//merge(v1.v2,target):������������������,�ϲ���Ҳ�������
	//copy(begin,end,destin
	//replace(begin,end,oldvalue,newvalue
	//replace_if(begin,end,pre,newvalue
	//swap(v1,v2
	//#include<numeric>  total =accumulate(begin,end,try),����tryΪ��ʼֵ
	vector<int> ::iterator k_find = find(v.begin(), v.end(), 3);
	if (k_find == v.end()) {
		cout << "���޲鵽" << endl;
	}//������Զ�����������,��ô������Ҫ����==�ŵ�,˵����ȵ�����
	else
	{
		cout << *k_find << endl;
	}

}








int main() {
	test();
	return 0;
}