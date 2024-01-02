#include<iostream>
#include<fstream>
#include<chrono>
#include<iomanip>
#include<string>
#include"Matrix_Chain_Order"
#include"LCS"
using namespace std;
#define COUNT 10000
int main(void)
{
    fstream f;
    long long* p[5];
    long long** m;
    int** s;
    int n[5];
    string x[5],y[5];
    int** c;
    char** b;

    f.open("../output/2_1/result.txt",ios::out|ios::trunc);//清空文件内容
    f.close();
    f.open("../output/2_1/time.txt",ios::out|ios::trunc);
    f.close();
    f.open("../output/2_2/result.txt",ios::out|ios::trunc);//清空文件内容
    f.close();
    f.open("../output/2_2/time.txt",ios::out|ios::trunc);
    f.close();

    //读取5组数据
    f.open("../input/2_1_input.txt",ios::in);
    for (int i = 0; i < 5; i++)
    {
        f >> n[i];
        p[i] = new long long[n[i]+1];
        for(int j = 0; j <= n[i]; j++)
        {
            f >> p[i][j];
        }
    }
    f.close();

    f.open("../input/2_2_input.txt",ios::in);
    for (int i = 0; i < 5; i++)
    {
        int j;
        f >> j;
        f >> j;
        f >> x[i];
        f >> y[i];
    }
    f.close();

    
    for(int k = 0; k < 5; k++)
    {
        auto start = chrono::high_resolution_clock::now();
        for(int i = 0; i < COUNT; i++)
        {
            Matrix_Chain_Order(p[k],m,s,n[k]);
            delete[] m,s;
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        f.open("../output/2_1/time.txt",ios::out|ios::app);
        f << setprecision(6) << fixed << duration.count() << '\n';
        f.close();
        Matrix_Chain_Order(p[k],m,s,n[k]);
        f.open("../output/2_1/result.txt",ios::out|ios::app);
        f << m[0][n[k]-1] << '\n';
        f.close();
        Print_Matrix_Chain_Order(s,0,n[k]-1);
        f.open("../output/2_1/result.txt",ios::out|ios::app);
        f << '\n';
        f.close();
        delete[] m,s;

        start = chrono::high_resolution_clock::now();
        for(int i = 0; i < COUNT; i++)
        {
            LCS(x[k],y[k],c,b);
            delete[] c,b;
        }
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        f.open("../output/2_2/time.txt",ios::out|ios::app);
        f << setprecision(6) << fixed << duration.count() << '\n';
        f.close();
        LCS(x[k],y[k],c,b);
        f.open("../output/2_2/result.txt",ios::out|ios::app);
        f << c[x[k].size()][y[k].size()] << '\n';
        f.close();
        Print_LCS(b,x[k],x[k].size(),y[k].size());
        f.open("../output/2_2/result.txt",ios::out|ios::app);
        f << '\n';
        f.close();
        delete[] c,b;
    }
    return 0;
}