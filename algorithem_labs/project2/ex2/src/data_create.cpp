#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
int main(void)
{
    fstream f;
    f.open("..\\input\\2_2_input.txt",ios::out|ios::trunc);
    srand(time(NULL));
    for(int i = 2;i <= 6; i++)
    {
        f << i * 5 << ' ' << i * 5 << '\n';
        for(int j = 1; j <= i * 5; j++)
        {
            f << (char)(rand() % 4 + 65);
        }
        f << '\n';
        for(int j = 1; j <= i * 5; j++)
        {
            f << (char)(rand() % 4 + 65);
        }
        f << '\n';
    }
    f.close();
    return 0;
}