#include<iostream>
#include"../BST_Node"
using namespace std;
int main(void)
{
    BST_Node<int,int>* my_node = new BST_Node<int,int>();
    cout << my_node->Get_Key() << '\n';
    cout << my_node->Get_Value() << '\n';
    my_node->Change_Key(5);
    cout << my_node->Get_Key() << '\n';
    
    // delete my_node;
    cout << my_node->Get_P() << '\n';

    BST_Node<int,int>* my_node1 = new BST_Node<int,int>(3);
    my_node->Change_P(my_node1);

    delete my_node;
    return 0;
}
