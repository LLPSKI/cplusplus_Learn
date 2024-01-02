#include<iostream>
#include<string>
#include<cstring>
// #include<algorithm>
using namespace std;
/*
ABCBDAB
BDCABA
输出为：BCBA
*/
char** LCS_length(string& x,string& y)
{
    int m=x.size(),n=y.size();
    int** c=new int*[m+1];
    char** b=new char*[m+1];
    for(int i=0;i<=m;i++)
    {
        c[i]=new int[n+1];
        b[i]=new char[n+1];
        memset(c[i],0,sizeof(int)*(n+1));
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='0';
            }else{
                if(c[i-1][j]>c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                    b[i][j]='1';
                }else 
                {
                    c[i][j]=c[i][j-1];
                    b[i][j]='2';
                }
            }
        }
    }
    cout<<c[m][n]<<' ';
    return b;
}
void print_LCS(char**& b,string& x,int i,int j)
{
    if(i==0||j==0)
    {
        return ;
    }
    if(b[i][j]=='0')
    {
        print_LCS(b,x,i-1,j-1);
        cout<<x[i-1];
    }else if(b[i][j]=='1')
    {
        print_LCS(b,x,i-1,j);
    }else print_LCS(b,x,i,j-1);
}
int main(void)
{
    string sub1,sub2;
    cin>>sub1>>sub2;
    char** b=LCS_length(sub1,sub2);
    print_LCS(b,sub1,sub1.size(),sub2.size());
    delete[] b;
    return 0;
}
