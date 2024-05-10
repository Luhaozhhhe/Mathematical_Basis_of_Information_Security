#include<iostream>
using namespace std;
bool isprime(int a) {
	bool flag = true;
	if (a < 2) {
		return false;
	}
	else {
		for (int i = 2; i * i <= a; i++) {
			if (a % i == 0) {
				flag = false;
			}

		}
		return flag;
	}
}
int findprime(int n) {
	int count = 0;//用于计录素数的个数
	bool* num = new bool[n + 1];
	for (int i = 1; i <= n; i++) {
		num[i] = true;//赋初始值，全部为true，表示都为素数
	}
	num[1] = false;//在Eratosthenes筛法中不会遍历到1这个数，因此先赋值为false
	for (int i = 2; i * i < n; i++) {
		if (isprime(i)) {
			for (int j = i + i; j <= n; j += i) {
				num[j] = false;//完成了Eratosthenes筛法的主要步骤
			}
		}

	}
	for (int i = 1; i <= n; i++) {
		if (num[i]) {
			count++;//用于计数
			
			cout << i << " ";
		}
	}
	cout << endl;
	return count;
}


int main() {
	int n;
	cout << "Please input the range:1-";
	cin >> n;
	int count = findprime(n);
	cout <<"Total:"<< count << endl;
	system("pause");

	return 0;
}