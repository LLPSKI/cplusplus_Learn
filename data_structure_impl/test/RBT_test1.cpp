#include<iostream>
#include<ctime>
#include"../RBT_impl"
using namespace std;
int main(void)
{
    int n;
    srand(time(NULL));
    cout<<"输入红黑树规模：";
    cin>>n;

    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);

    RBT<int,int>* mytree = new RBT<int,int>;
    double start,end;
    cout<<"进行3次删除和3次插入交替操作\n";
    for(int i = 0;i < n;i++)
    {
        mytree->Insert(rand());
    }
    for(int i = 0;i < (n / 2);i++)
    {
        mytree->Delete(mytree->Search(mytree->T,rand()));
    }
    // //cout<<"红黑树黑高为"<<mytree->RBT_BH(mytree->T)<<'\n';

    for(int i = 0;i < (n / 2);i++)
    {
        mytree->Insert(rand());
    }
    for(int i = 0;i < (n / 2);i++)
    {
        mytree->Delete(mytree->Search(mytree->T,rand()));
    }
    // //cout<<"红黑树黑高为"<<mytree->RBT_BH(mytree->T)<<'\n';

    for(int i = 0;i < (n / 2);i++)
    {
        mytree->Insert(rand());
    }
    for(int i = 0;i < (n / 2);i++)
    {
        mytree->Delete(mytree->Search(mytree->T,rand()));
    }
    //cout<<"红黑树黑高为"<<mytree->RBT_BH(mytree->T)<<'\n';
    

    // while(true)
    // {
    //     char op;
    //     int key;
    //     cin>>op;
    //     switch(op)
    //     {
    //         case('i'):
    //             cin >> key;
    //             if(mytree->Insert(key))
    //             {
    //                 cout << "插入成功！\n";
    //             }
    //             break;
    //         case('c'):
    //             cout << mytree->Node_Number<<'\n';
    //             break;
    //         case('p'):
    //             mytree->In_Order_Traversal(mytree->T);
    //             cout << '\n';
    //             break;
    //         case('d'):
    //             cin >> key;
    //             mytree->Delete(mytree->Search(mytree->T,key));
    //             break;
    //         case('q'):
    //             // delete mytree;
    //             break;
    //     }
    // }

    while(true)
    {
        cout<<"输入搜索规模：";
        cin>>n;
        int success_time = 0,faliure_time = 0;
        start = clock();
        for(int i = 0;i < n;i++)
        {
            if(mytree->Search(mytree->T,rand())->is_nil == false)
            {
                success_time++;
            }
            else 
            {
                faliure_time++;
            }
        }
        end = clock();
        cout<<"搜索时间为"<<(end - start) / CLK_TCK<<'\n';
        cout<<"搜索成功次数："<<success_time<<'\n';
        cout<<"搜索失败次数："<<faliure_time<<'\n';
    }
    

    return 0;
}