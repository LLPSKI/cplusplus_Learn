#include<iostream>
#include<ctime>
#include"BST_impl"
using namespace std;
int main(void)
{
    int n;
    srand(time(NULL));
    cout<<"输入搜索树规模：";
    cin>>n;

    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);

    BST<int,int>* mytree = new BST<int,int>;
    double start,end;
    cout<<"进行3次删除和3次插入交替操作\n";
    for(int i = 0;i < n;i++)
    {
        mytree->Insert(rand()%20000+1);
    }
    for(int i = 0;i < (n / 2);i++)
    {
        mytree->Delete(mytree->Search(mytree->T,rand()%20000+1));
    }
    // //cout<<"红黑树黑高为"<<mytree->RBT_BH(mytree->T)<<'\n';

    for(int i = 0;i < (n / 2);i++)
    {
        mytree->Insert(rand()%20000+1);
    }
    for(int i = 0;i < (n / 2);i++)
    {
        mytree->Delete(mytree->Search(mytree->T,rand()%20000+1));
    }
    // //cout<<"红黑树黑高为"<<mytree->RBT_BH(mytree->T)<<'\n';

    for(int i = 0;i < (n / 2);i++)
    {
        mytree->Insert(rand()%20000+1);
    }
    for(int i = 0;i < (n / 2);i++)
    {
        mytree->Delete(mytree->Search(mytree->T,rand()%20000+1));
    }
    // cout<<"红黑树黑高为"<<mytree->RBT_BH(mytree->T)<<'\n';
    // cout<<"对红黑树进行结点中序遍历如下：";
    // mytree->In_Order_Traversal(mytree->T,1);
    while(true)
    {
        cout<<"输入搜索规模：";
        cin>>n;
        int success_time = 0,faliure_time = 0;
        start = clock();
        for(int i = 0;i < n;i++)
        {
            if(mytree->Search(mytree->T,rand()))
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