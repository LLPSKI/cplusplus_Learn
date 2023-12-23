#include<iostream>
#include"BST_impl"
using namespace std;
int main(void)
{
    BST<int,int>* mytree = new BST<int,int>();
    /*
        定义指令：
            i key
            d key
    */
    while(true)
    {
        char op;
        int key;
        cin>>op;
        switch(op)
        {
            case('i'):
                cin>>key;
                if(mytree->Insert(key))
                {
                    cout<<"插入成功！\n";
                }
                break;
            case('c'):
                cout<<mytree->Current_Node_Number()<<'\n';
                break;
            case('p'):
                mytree->In_Order_Traversal(mytree->Root());
                cout<<'\n';
                break;
            case('d'):
                cin>>key;
                mytree->Delete(mytree->Search(mytree->Root(),key));
                break;
            case('q'):
                return 0;
        }
    }
    return 0;
}