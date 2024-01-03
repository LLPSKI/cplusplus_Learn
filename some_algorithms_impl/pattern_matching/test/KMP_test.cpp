#include<iostream>
#include"../KMP_impl"
using namespace std;
int main(void)
{
    char P[] = "ababaca";
    char* P1 = new char[8];
    for(int i = 1; i <= 7; i++)
    {
        P1[i] = P[i-1];
    }
    unsigned int* PI = Compute_Prefix<char>(P1,7);
    for(int i = 1; i <= 7; i++)
    {
        cout << PI[i] << ' ';
    }
    return 0;
}