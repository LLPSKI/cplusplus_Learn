#include<iostream>
#include<fstream>
#include"RK_impl"
#include"KMP_impl"
using namespace std;
int main(void)
{
    fstream f;
    char* P1 = new char[21];
    char* P2 = new char[31];
    char* P3 = new char[51];
    char* T = new char[2001];
    int q = 80;
    int d = 26;

    //将三个模式串读入
    f.open("..\\input\\input.txt",ios::in);
    for(int i = 0;i < 3;i++)
    {
        int k;
        char* P;
        switch (i)
        {
        case(0):
            k = 20;
            P = P1;
            break;
        case(1):
            k = 30;
            P = P2;
            break;
        case(2):
            k = 50;
            P = P3;
            break;
        default:
            break;
        }
        for(int j = 0;j < k;j++)
        {
            f >> P[j];
        }
        P[k] = '\0';
    }
    
    for(int i = 0;i < 10;i++)
    {
        int k = 200 * (i + 1);
        for(int j = 0;j < k;j++)
        {
            f >> T[j];
        }
        T[k] = '\0';
        cout << k << ":\n";
        // RK<char>(P1,20,T,k,q,d);
        // RK<char>(P2,30,T,k,q,d);
        // RK<char>(P3,50,T,k,q,d);
        KMP<char>(P1,20,T,k);
        KMP<char>(P2,30,T,k);
        KMP<char>(P3,50,T,k);
    }
    return 0;
}