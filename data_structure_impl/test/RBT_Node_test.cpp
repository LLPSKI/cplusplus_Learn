#include<iostream>
#include"../RBT_Node"
using namespace std;
int main(void)
{
    RBT_Node<int,int>* p = new RBT_Node<int,int>();
    delete p;
    int* a = new int[1];
    *a = 6;
    p = new RBT_Node<int,int>(5,a);
    delete p;
    return 0;
}