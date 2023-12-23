#include<iostream>
#include<cstring>
using namespace std;
/*
3 50
60 100 120
10 20 30
*/

int** knapsack_0_1(int*& v,int*& w,int W,int n)
{
    int** c = new int*[n+1];
    for(int i = 0;i < n + 1;i++)
    {
        c[i] = new int[W+1];
        memset(c[i],0,sizeof(int)*(W+1));
    }
    for(int i = 1;i < n + 1;i++)
    {
        for(int j = 1;j < W + 1;j++)
        {
            if(j < w[i-1])
            {
                c[i][j] = c[i-1][j];
            }else if(j >= w[i-1])
            {
                if((v[i-1] + c[i-1][j-w[i-1]]) > c[i-1][j])
                {
                    c[i][j] = v[i-1] + c[i-1][j-w[i-1]];
                }else c[i][j] = c[i-1][j];
            }
            cout << "c[" << i << "][" << j << "]=" << c[i][j] << '\t';
        }
        cout << '\n';
    }
    return c;
}

int main(void)
{
    int n,W;
    cin >> n >> W;
    int* v = new int[n];
    int* w = new int[n];
    for(int i = 0;i < n;i++)
    {
        cin >> v[i];
    }
    for(int i = 0;i < n;i++)
    {
        cin >> w[i];
    }
    int** c = knapsack_0_1(v,w,W,n);
    
    return 0;
}