#include <bits/stdc++.h>  
using namespace std;
int m;
void binary(vector<int>& a, int temp)
{//实现了十进制转二进制
    int q = temp;
    int r;
    while (q != 0)
    {
        r = q % 2;
        a.push_back(r);
        q = q / 2;
    }
}
int quick_pow(int a, int n, int m) {//是第二章中的练习，实现了平方乘-快速幂算法
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

bool isprime(int a) {//判断一个数是不是素数
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

void depart_the_num(int n, vector<int>& res)
{//这部分是用递归的方法求解出一个数的质因数分解的结果
    int l = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isprime(i))
        {
            if (n % i == 0)
            {
                l++;
                res[i]++;
                int t = n / i;
                m = t;
                depart_the_num(t, res);
                break;
            }
        }
    }
    if (!l)
        res[m]++;
}
int Euler_totient_function(int n)
{//这部分我们实现了欧拉函数的计算
    vector<int> vec(10000, 0);
    depart_the_num(n, vec);
    int euler = n;
    for (int i = 2; i < vec.size(); i++)
    {
        if (vec[i] != 0)
            euler *= (1 - 1 / double(i));
    }
    return euler;
}
int main()
{
    cout << "Please input n(n>0): ";
    int n;
    cin >> n;
    int euler = Euler_totient_function(n);
    int g = 0;
    vector<int> exp;
    vector<int> res(10000);
    depart_the_num(euler, res);
    for (int i = 2; i < res.size(); i++)
    {
        if (res[i] != 0)
            exp.push_back(euler / i);
    }
    for (int i = 2; i < n; i++)
    {
        bool flag = 1;
        for (int j = 0; j < exp.size(); j++)
        {
            int t = quick_pow(i, exp[j], n);
            if (t == 1)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            g = i;
            break;
        }
    }
    cout << "The min primitive root of " << n << ": g=" << g << endl;
    cout << "The ind_table of " << n << " based on g=" << g << " is:" << endl;
    cout << setw(6) << " ";
    for (int i = 0; i < 10; i++)
        cout << setw(6) << i;
    cout << endl;
    int row = n / 10;
    int** table = new int* [row + 1];
    for (int i = 0; i < row + 1; i++)
    {
        table[i] = new int[11];
        table[i][0] = i;
        for (int j = 1; j < 11; j++)
            table[i][j] = -1;
    }
    for (int i = 0; i <= euler - 1; i++)
    {
        int t = quick_pow(g, i, n);
        int row_num = t / 10;
        int col_num = t % 10;
        table[row_num][col_num + 1] = i;
    }
    for (int i = 0; i < row + 1; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (table[i][j] != -1)
                cout << setw(6) << table[i][j];
            else
                cout << setw(6) << "-";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}