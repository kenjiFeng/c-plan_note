//#include<iostream>	
//#include<vector>
//#include<string>
//using namespace std;
//#include<algorithm>
//
//void test() {
//	int k = 0;
//	cout << "��������Ҫ�������������" << endl;
//	cin >> k;
//	string b = "&";
//	vector<string>zixu1;
//	vector<string>zixu2;
//	int a = 0;
//	while ( a < k) {
//		cout << "�������" << a+1 << "��������1���ַ���" << endl;
//		string a1;
//		cin >> a1;
//		while (a1.size() > 1000) {
//			cout << "���������ַ�����������1000,��������" << endl;
//			cin >> a1;
//		}
//		zixu1.push_back(a1);
//		cout << "�������" << k << "��������2���ַ���" << endl;
//		string c1;
//		cin >> c1;
//		
//		while (c1.size() > 1000) {
//			cout << "���������ַ�����������1000,��������" << endl;
//			cin >> c1;
//		}
//		zixu2.push_back(c1);
//		++a;
//	}
//	for (vector<string>::iterator k1 = zixu1.begin(), k2 = zixu2.begin(); k1 != zixu1.end() && k2 != zixu2.end();
//		k1++, k2++)
//	{
//		for (int i = 0; i < k1->size(); i++) {
//			string c = *k1;
//			string d = *k2;
//			if (c[i] == d[i] && k1->size() == k2->size()&&i+1==k1->size()) {
//				cout << "YES" << endl;
//				cout << *k1 << " " << "&" << " " << *k2 << endl;
//				
//
//			}
//			if (c[i] != d[i] && k1->size() != k2->size()) {
//				cout << "NO" << endl;
//				cout << *k1 << " " << "&" << " " << *k2 << endl;
//				break;
//
//			}
//
//		}
//	}
//
//}
//
//int fibo(int a) {
//	if (a==1 || a==0)
//	{
//		return a;
//	}
//	return fibo(a - 1) + fibo(a - 2);
//}
//
//int main(){
//	 int k=fibo(8);
//	 cout << k << endl;
//	return 0;
//}