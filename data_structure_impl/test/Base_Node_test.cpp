#include<iostream>
#include"../Base_Node"
using namespace std;
int main(void)
{
    Base_Node<int,int>* p = new Base_Node<int,int>();
    delete p;
    p = new Base_Node<int,int>(5);
    delete p;
    int* a = new int[1];
    *a = 5;
    p = new Base_Node<int,int>(3,a);
    delete p;
    return 0;
}