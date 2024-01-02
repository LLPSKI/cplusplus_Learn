#include<iostream>
#include<string>
#include"../LCS"
using namespace std;
/*
ABCBDAB
BDCABA
输出为：BCBA
*/
int main(void)
{
    string x,y;
    cin >> x >> y;
    int** c;
    char** b;
    LCS(x,y,c,b);
    cout << c[x.size()][y.size()] << ' ';
    Print_LCS(b,x,x.size(),y.size());
    return 0;
}