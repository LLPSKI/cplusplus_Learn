#include<iostream>
#include"../Matrix_Chain_Order"
using namespace std;
/*
6
30 35 15 5 10 20 25
5
24328 18379 35569 67278 49933 36006
*/
int main(void)
{
    int n;
    cin >> n;
    long long* p = new long long[n+1];
    long long** m;
    int** s;
    for(int i = 0; i < n + 1; i++)
    {
        cin >> p[i];
    }
    Matrix_Chain_Order(p,m,s,n);
    for(int l = n; l >= 2; l--)
    {
        for(int i = 0; i < (n - l + 1); i++)
        {
            int j = i + l - 1;
            cout << m[i][j] << ' ';
        }
        cout << '\n';
    }
    for(int l = n; l >= 2; l--)
    {
        for(int i = 0; i < (n - l + 1); i++)
        {
            int j = i + l - 1;
            cout << s[i][j] << ' ';
        }
        cout << '\n';
    }
    Print_Matrix_Chain_Order(s,0,n-1);
    delete[] m,s;
    return 0;
}