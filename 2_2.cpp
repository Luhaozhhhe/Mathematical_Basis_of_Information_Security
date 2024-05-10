#include<iostream>
using  namespace std;
void swap(int &a, int &b) {//change the two numbers
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int oujilide(int a, int b, int& temp1, int& temp2) {
	if (a < b) {
		return oujilide(b, a, temp2, temp1);
	}
	int a0 = a; int b0 = b; int q = 1;
	int s0 = 1; int s1 = 0; int t0 = 0; int t1 = 1;
	while (a % b != 0) {
		q = a / b;
		a = a % b;
		swap(a, b);
		s0 = s0 - q * s1;
		swap(s0, s1);
		t0 = t0 - q * t1;
		swap(t0, t1);

	}
	temp1 = s1;
	temp2 = t1;
	if (temp1 <= 0) {
		temp1 = temp1 + b0;
	}
	if (temp2 <= 0) {
		temp2 = temp2 + a0;
	}
	return b;
}
int main() {
	int a; int b; int temp1; int temp2;
	
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	int gcd = oujilide(a, b, temp1, temp2);
	int lcm = a * b / gcd;
	cout << "gcd(a,b)=" << gcd << endl;
	cout << "lcm(a,b)=" << lcm << endl;
	cout << "a^(-1)=" << temp1 << "(mod " << b << ")" << endl;
	cout << "b^(-1)=" << temp2 << "(mod " << a << ")" << endl;
	system("pause");
	return 0;
}