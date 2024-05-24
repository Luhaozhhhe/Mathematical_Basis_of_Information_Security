#include<iostream>
using namespace std;

bool isprime(int n)
{
	if (n < 2)return false;
	bool flag = true;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

void suanshufenjie(int n) {
	if (n == 1) {
		cout << "1^1" << endl; return;
	}
	if (isprime(n)) {
		cout << n << "^1"; cout << endl;
	}
	else {
		int count = 0; bool temp = true;
		for (int i = 2; i * i < n; i++) {
			if (n % i == 0) {
								
				while (!(n % i)){
					count++;
					n = n / i;
				}
				if (!temp) {
					cout << "*";
				}
				temp = false;
			}
			cout << i<<"^" << count ;
			if (n == 1) {
				cout << endl; return;
			}
			count = 0;
			if (isprime(n)) {
				cout << "*";
				cout << n << "^1"; cout << endl; return;
			}
		}
	}
}


int main() {
	int n;
	cout << "Please input n(n>0):";
	cin>>n;
	cout << n<<"=";
	suanshufenjie(n);
	system("pause");


	return 0;
}


