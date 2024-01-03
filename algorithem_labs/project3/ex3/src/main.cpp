#include<iostream>
#include<fstream>
#include<chrono>
#include<iomanip>
#include"RBT_impl"
using namespace std;
#define COUNT 9999
int main(void)
{
    fstream f, f1;
    RBT<int,int>* mytree;
    
    // f1.open("../output/inorder.txt",ios::out|ios::trunc);//清空内容
    // f1.close();
    // f1.open("../output/delete_data.txt",ios::out|ios::trunc);//清空内容
    // f1.close();
    f1.open("../output/time1.txt",ios::out|ios::trunc);//清空内容
    f1.close();
    // f1.open("../output/time2.txt",ios::out|ios::trunc);//清空内容
    // f1.close();
    f.open("../input/input.txt",ios::in);
    for(int i = 1; i <= 5; i++)
    {
        //读取i*20规模的数据
        int n = i * 20;
        int* P = new int[n];
        for(int j = 1; j <= n; j++)
        {
            f >> P[j-1];
        }
        chrono::duration<double> duration;

        mytree = new RBT<int,int>();
        auto start = chrono::high_resolution_clock::now();
        for(int j = 1; j <= n; j++)
        {
            
            mytree->Insert(P[j-1]);
        }
        auto end = chrono::high_resolution_clock::now();
        duration = end - start;
        // auto start = chrono::high_resolution_clock::now();
        // for(int j = 1; j <= (n / 4); j++)
        // {
        //     mytree->Delete(mytree->T);//每一次将根节点删掉
        // }
        // auto end = chrono::high_resolution_clock::now();
        // duration = end - start;

        for(int k = 1; k <= COUNT; k++)
        {
            delete mytree;
            mytree = new RBT<int,int>();
            auto start = chrono::high_resolution_clock::now();
            for(int j = 1; j <= n; j++)
            {
                
                mytree->Insert(P[j-1]);
            }
            auto end = chrono::high_resolution_clock::now();
            duration += end - start;
            // auto start = chrono::high_resolution_clock::now();
            // for(int j = 1; j <= (n / 4); j++)
            // {
            //     mytree->Delete(mytree->T);//每一次将根节点删掉
            // }
            // auto end = chrono::high_resolution_clock::now();
            // duration += end - start;
        }
        f1.open("../output/time1.txt",ios::out|ios::app);
        f1 << setprecision(6) << fixed << duration.count() << "\n\n";
        f1.close();
        delete mytree;
        // mytree->In_Order_Traversal(mytree->T);
        // f1.open("../output/inorder.txt",ios::out|ios::app);
        // f1 << "\n\n";
        // f1.close();

        // for(int j = 1; j <= (n / 4); j++)
        // {
        //     mytree->Delete(mytree->T);//每一次将根节点删掉
        // }
        // mytree->In_Order_Traversal(mytree->T);
        // f1.open("../output/delete_data.txt",ios::out|ios::app);
        // f1 << "\n\n";
        // f1.close();
        
    }
    return 0;
}