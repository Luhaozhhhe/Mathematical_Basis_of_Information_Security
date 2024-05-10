#include<iostream>
using namespace std;
int gcd(int a, int b) {
	if (a < 0) {
		a = -a;
	}
	if (b < 0) {
		b = -b;
	}
	int temp = a;
	while (temp != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main() {
	int a;
	int b;
	cout << "a=";
	cin >> a;
	cout << endl;
	cout << "b=";
	cin >> b;
	cout << endl;
	cout << "gcd(a,b)=" << gcd(a, b) << endl;
	cout << "lcm(a,b)=" << lcm(a, b) << endl;
	system("pause");



	return 0;
}