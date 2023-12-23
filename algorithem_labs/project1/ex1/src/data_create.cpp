#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
int main(void)
{
    fstream f;
    f.open("..\\input\\input.txt",ios::out);
    srand(time(NULL));
    for(int i = 0;i < 300000;i++)
    {
        f<<rand()<<'\n';
    }
    f.close();
    return 0;
}