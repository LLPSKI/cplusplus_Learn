#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
int main(void)
{
    fstream f;
    srand(time(NULL));
    f.open("../input/input.txt",ios::out|ios::trunc);
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= i * 20; j++)
        {
            f << (rand() % 999) + 1 << ' ';
        }
        f << '\n' << '\n';
    }
    f.close();
    return 0;
}