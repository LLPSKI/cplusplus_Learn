#include<iostream>
using namespace std;

int DP_minimum_coin(int *type,int type_number,int *s,int a)
{
    int *r=new int[a+1];
    r[0]=0;
    for(int j=1;j<=a;j++)
    {
        int q=INT_MAX;
        for(int k=0;k<type_number;k++)
        {
            if(type[k]<=j)
            {
                q=min(q,1+r[j-type[k]]);
                s[j]=k;
            }
        }
        r[j]=q;
        cout<<"r["<<j<<"]="<<r[j]<<" ";
    }
    return r[a];
}
void print_scheme(int *s,int *type,int a)
{
    while(a>0)
    {
        cout<<type[s[a]]<<' ';
        a-=type[s[a]];
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int type[]={1,5,10,25,50};
    int a;
    cin>>a;
    int *s=new int[a+1];
    DP_minimum_coin(type,5,s,a);
    print_scheme(s,type,a);
    return 0;
}