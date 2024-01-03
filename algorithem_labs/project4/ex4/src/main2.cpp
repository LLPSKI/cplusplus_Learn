#include<iostream>
#include<fstream>
#include<string>
#include<chrono>
#include<iomanip>
#include"RK_impl"
#include"KMP_impl"
using namespace std;

#define COUNT 100000
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
    f1.open("../output/KMP/time.txt",ios::out|ios::trunc);
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

        f1.open("../output/KMP/time.txt",ios::out|ios::app);
        f1 << "规模" << k << ":\n";
        auto start = chrono::high_resolution_clock::now();
        for(int l = 1; l <= COUNT; l++)
        {
            KMP<char>(P1,20,T,k);
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        f1 << setprecision(6) << fixed << duration.count() << '\n';

        start = chrono::high_resolution_clock::now();
        for(int l = 1; l <= COUNT; l++)
        {
            KMP<char>(P2,30,T,k);
        }
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        f1 << setprecision(6) << fixed << duration.count() << '\n';

        start = chrono::high_resolution_clock::now();
        for(int l = 1; l <= COUNT; l++)
        {
            KMP<char>(P3,50,T,k);
        }
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        f1 << setprecision(6) << fixed << duration.count() << '\n';\
        f1.close();
    }
    f.close();

    f.open("../input/input.txt",ios::in);
    f1.open("../output/RK/time.txt",ios::out|ios::trunc);
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
        f1.open("../output/RK/time.txt",ios::out|ios::app);
        f1 << "规模" << i * 200 << ":\n";
        auto start = chrono::high_resolution_clock::now();
        for(int l = 1; l <= COUNT; l++)
        {
            RK(P11,T1,1000000007,5);
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        f1 << setprecision(6) << fixed << duration.count() << '\n';
        
        start = chrono::high_resolution_clock::now();
        for(int l = 1; l <= COUNT; l++)
        {
            RK(P12,T1,1000000007,5);
        }
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        f1 << setprecision(6) << fixed << duration.count() << '\n';

        start = chrono::high_resolution_clock::now();
        for(int l = 1; l <= COUNT; l++)
        {
            RK(P13,T1,1000000007,5);
        }
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        f1 << setprecision(6) << fixed << duration.count() << '\n';\
        f1.close();
    }
    f.close();
    return 0;
}