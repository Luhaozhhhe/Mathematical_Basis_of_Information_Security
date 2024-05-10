#include<iostream>
using namespace std;
//平方-乘算法
int pingfangcheng(int a, int n, int m) {
	int result = 1;
	while (n > 0) {
		if (n & 1) {
			result *= a;
			result %= m;
		}
		a *= a;
		a %= m;
		n >>= 1;//利用位运算来实现算法
	}
	return result;
}
int main() {
	int a; int m; int n;
	cout << "Calculate a^n(mod m)..." << endl;
	cout << "Please input:" << endl;
	cout << "   a="; cin >> a;
	cout << "   n="; cin >> n;
	cout << "   m="; cin >> m;
	cout << a << "^" << n << "(mod " << m << ")=" << pingfangcheng(a, n, m) << endl;


	system("pause");

	return 0;
}