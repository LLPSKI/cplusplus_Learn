#include<iostream>
#include<cstring>
using namespace std;
unsigned int n;
unsigned int count;
int* arr;
void UpRing(unsigned int n);
void Display(void);
void DonwRing(unsigned int n)//取下前n个环
{
    if(n > 2)//如果n < 2的情况，会出错
    {
        DonwRing(n - 2);//需要先把前n-2个环取下
        cout<<"取下第"<<n<<"个环\n";//再将第n个环取下
        arr[n-1] = 1;
        Display();
        count++;
        //此时第n-1个环还没有取下，需要先将前n-2个环放上，再取下第n-1个环
        UpRing(n - 2);
        DonwRing(n - 1);
    }
    else if(n == 2)
    {   
        //如果n = 2的话，直接取下即可，但此时第一个环还在上面
        cout<<"取下第"<<n<<"个环\n";//将第2个环取下
        arr[n-1] = 1;
        Display();
        cout<<"取下第"<<(n - 1)<<"个环\n";//再将第1个环取下
        arr[n - 2] = 1;
        Display();
        count++;
        count++;
    }
    else 
    {
        //如果n = 1的话，直接取下即可
        cout<<"取下第"<<n<<"个环\n";//将第1个环取下
        arr[n - 1] = 1;
        Display();
        count++;
    }
}

void UpRing(unsigned int n)
{
    
    if(n > 2)//如果n < 2的情况，会出错
    {
        UpRing(n - 1);//需要先把前n-1个环放上
        DonwRing(n - 2);//再把前n-2个环取下
        cout<<"放上第"<<n<<"个环\n";//将第n个环放上
        count++;
        arr[n - 1] = 0;
        Display();
        UpRing(n - 2);
    }
    else if(n == 2)
    {   
        //如果n = 2的话，先放上第1个环，再放上第2个环
        cout<<"放上第"<<(n - 1)<<"个环\n";//将第1个环放上
        arr[n - 2] = 0;
        Display();
        cout<<"放上第"<<n<<"个环\n";//再将第2个环放上
        arr[n - 1] = 0;
        Display();
        count++;
        count++;
    }
    else 
    {
        //如果n = 1的话，直接放上即可
        cout<<"放上第"<<n<<"个环\n";//将第1个环放上
        arr[n - 1] = 0;
        Display();
        count++;
    }
}
void Display(void)
{
    for(int i = n - 1;i >= 0;i--)
    {
        cout<<arr[i];
    }
    cout<<'\n';
}
int main(void)
{
    while(1)
    {
        cin>>n;
        count = 0;
        arr = new int[n];
        memset(arr,0,sizeof(int)*n);
        DonwRing(n);
        cout<<"count = "<<count<<'\n';
    }
    return 0;
}
