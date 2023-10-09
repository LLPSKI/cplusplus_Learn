#include<iostream>
#include<cstring>
using namespace std;
/*
1 5 8 9 10 17 17 20 24 30
*/
int DC_cut_rod(int *p,int n,int *s)
{
    if(n==0)
    {
        return 0;
    }
    int q=INT_MIN;
    for(int k=1;k<=min(n,11);k++)
    {
        q=max(q,p[k]+DC_cut_rod(p,n-k,s));

    }
    return q;
}
int DP_cut_rod(int *p,int n)
{
    if(n==0)
    {
        return 0;
    }
    int *r=new int[n+1];
    r[0]=0;
    for(int k=1;k<=n;k++)
    {
        int q=INT_MIN;
        for(int j=1;j<=k;j++)
        {
            q=max(q,p[k]+r[k-j]);
        }
    }
}

int main(void)
{
    int arr[]={0,1,5,8,9,10,17,17,20,24,30};
    int n;
    cin>>n;
    int *s=new int[n];
    cout<<DC_cut_rod(arr,n,s);
}