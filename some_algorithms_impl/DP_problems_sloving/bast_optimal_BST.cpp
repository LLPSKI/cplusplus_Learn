#include<iostream>
using namespace std;
/*
5
     0.15 0.10 0.05 0.10 0.20
0.05 0.10 0.05 0.05 0.05 0.10
7
     0.04 0.06 0.08 0.02 0.10 0.12 0.14
0.06 0.06 0.06 0.06 0.05 0.05 0.05 0.05
*/
void optimal_BST(double*& p,double*& q,int n)
{
    double** e=new double*[n+2];
    double** w=new double*[n+2];
    int** root=new int*[n+1];
    for(int i=1;i<=n+1;i++)
    {//第0行就不申请空间了
        e[i]=new double[n+1];
        w[i]=new double[n+1];
        root[i]=new int[n+1];
        e[i][i-1]=q[i-1];
        w[i][i-1]=q[i-1];
    }
    for(int l=1;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            e[i][j]=__LDBL_MAX__;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            // cout<<"w["<<i<<"]["<<j<<"]="<<w[i][j]<<'\n';
            double temp;
            for(int r=i;r<=j;r++)
            {
                temp=e[i][r-1]+e[r+1][j]+w[i][j];
                if(temp<e[i][j])
                {
                    e[i][j]=temp;
                    root[i][j]=r;
                }
            }
            // cout<<"e["<<i<<"]["<<j<<"]="<<e[i][j]<<'\n';
            cout<<"root["<<i<<"]["<<j<<"]="<<root[i][j]<<'\n';
        }
    }
    cout<<e[1][n];
}
int main(void)
{
    int n;
    cin>>n;
    double *p=new double[n+1];
    double *q=new double[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    for(int i=0;i<=n;i++)
    {
        cin>>q[i];
    }
    optimal_BST(p,q,n);
    return 0;
}