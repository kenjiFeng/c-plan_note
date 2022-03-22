#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//创建仿函数
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
	//遍历1:tranform
	transform(v.begin(), v.end(), v1.begin(), fanghanshu1());
	//遍历2:for_each
	for_each(v.begin(), v.end(), fanghanshu());
	for (vector<int> ::iterator k = v1.begin(); k != v1.end(); k++) {
		cout << *k << endl;
	}
	//常用查找算法
	//find_if(begin\end\谓词)
	//count_if(begin\end\谓词)
	//adjacent_find 查找相邻重复元素
	//binary_find 二分查找数据,但是返回值是真或者假  前提是有序的序列
	//random_shuffle(begin,end
	//merge(v1.v2,target):两个容器必须是有序,合并后也是有序的
	//copy(begin,end,destin
	//replace(begin,end,oldvalue,newvalue
	//replace_if(begin,end,pre,newvalue
	//swap(v1,v2
	//#include<numeric>  total =accumulate(begin,end,try),其中try为起始值
	vector<int> ::iterator k_find = find(v.begin(), v.end(), 3);
	if (k_find == v.end()) {
		cout << "并无查到" << endl;
	}//如果是自定义数据类型,那么我们需要重载==号的,说明相等的条件
	else
	{
		cout << *k_find << endl;
	}

}








int main() {
	test();
	return 0;
}