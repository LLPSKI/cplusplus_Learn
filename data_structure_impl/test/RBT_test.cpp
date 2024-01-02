#include<iostream>
#include"../RBT_impl"
using namespace std;
int main(void)
{
    RBT<int,int>* mytree = new RBT<int,int>();
    while(true)
    {
        char op;
        int key;
        cin>>op;
        switch(op)
        {
            case('i'):
                cin >> key;
                if(mytree->Insert(key))
                {
                    cout << "插入成功！\n";
                }
                break;
            case('c'):
                cout << mytree->Node_Number<<'\n';
                break;
            case('p'):
                mytree->In_Order_Traversal(mytree->T);
                cout << '\n';
                break;
            case('d'):
                cin >> key;
                mytree->Delete(mytree->Search(mytree->T,key));
                break;
            case('q'):
                delete mytree;
                return 0;
        }
    }
    return 0;
}