#include<iostream>
#include<fstream>
#include<string>
#include<chrono>
#include"RK_impl"
#include"KMP_impl"
using namespace std;
int main(void)
{
    fstream f, f1;
    char* P1 = new char[22];
    char* P2 = new char[32];
    char* P3 = new char[52];
    string P11, P12, P13, T1;
    char* T = new char[2002];
    int q = 80;
    int d = 26;

    //将三个模式串读入
    f.open("..\\input\\input.txt",ios::in);
    f1.open("../output/KMP/result.txt",ios::out|ios::trunc);
    f1.close();
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
        for(int j = 1; j <= k; j++)
        {
            f >> P[j];
        }
        P[k+1] = '\0';
    }
    
    for(int i = 0;i < 10;i++)
    {
        int k = 200 * (i + 1);
        for(int j = 1 ;j <= k; j++)
        {
            f >> T[j];
        }
        T[k] = '\0';
        f1.open("../output/KMP/result.txt",ios::out|ios::app);
        f1 << "规模" << k << ":\n";
        f1 << "\n模式P1\n";
        f1.close();
        KMP<char>(P1,20,T,k);
        f1.open("../output/KMP/result.txt",ios::out|ios::app);
        f1 << "\n模式P2\n";
        f1.close();
        KMP<char>(P2,30,T,k);
        f1.open("../output/KMP/result.txt",ios::out|ios::app);
        f1 << "\n模式P3\n";
        f1.close();
        KMP<char>(P3,50,T,k);
        f1.open("../output/KMP/result.txt",ios::out|ios::app);
        f1 << "\n\n\n";
        f1.close();
    }
    f.close();

    f.open("../input/input.txt",ios::in);
    f1.open("../output/RK/result.txt",ios::out|ios::trunc);
    f1.close();
    for(int i = 1; i <= 3; i++)
    {
        switch (i)
        {
        case 1:
            f >> P11;
            break;
        case 2:
            f >> P12;
            break;
        case 3:
            f >> P13;
            break;
        }
    }
    for(int i = 1; i <= 10; i++)
    {
        f >> T1;
        f1.open("../output/RK/result.txt",ios::out|ios::app);
        f1 << "规模" << i * 200 << ":\n";
        f1 << "\n模式P1\n";
        f1.close();
        RK(P11,T1,1000000007,5);
        f1.open("../output/RK/result.txt",ios::out|ios::app);
        f1 << "\n模式P2\n";
        f1.close();
        RK(P12,T1,1000000007,5);
        f1.open("../output/RK/result.txt",ios::out|ios::app);
        f1 << "\n模式P3\n";
        f1.close();
        RK(P13,T1,1000000007,5);
        f1.open("../output/RK/result.txt",ios::out|ios::app);
        f1 << "\n\n\n";
        f1.close();
    }
    f.close();
    return 0;
}