#include<iostream>
#include"RBT_impl"
using namespace std;
int main(void)
{
    RBT<int,int>* mytree = new RBT<int,int>();
    RBT<int,int>::iterator p = mytree->Insert(5);
    cout<<mytree->T->key<<'\n';
    cout<<p->color<<'\n';
    
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
                mytree->In_Order_Traversal(mytree->Root(),1);
                cout<<'\n';
                break;
            case('d'):
                cin>>key;
                mytree->Delete(mytree->Search(mytree->Root(),key));
                break;
            case('q'):
                return 0;
            case('k'):
                cout<<"当前红黑树的黑高为"<<mytree->RBT_BH(mytree->T)<<'\n';
                break;
        }
    }
    return 0;
}