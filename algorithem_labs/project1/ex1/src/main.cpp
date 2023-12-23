#include<iostream>
#include<fstream>
#include<cmath>
#include<ctime>
#include<iomanip>
#include"insert_sort_impl"
#include"merge_sort_impl"
#include"heap_sort_impl"
#include"quick_sort_impl"
#include"counting_sort_impl"
using namespace std;
int main(void)
{
    int* arr = new int[300000];
    fstream f;
    int n[] = {3,6,9,12,15,18};
    int N;
    double start,end;


    // f.open("..\\output\\insert_sort\\time.txt",ios::out|ios::trunc);//先清空内容
    // f.close();
    // for(int k = 0;k < 6;k++)
    // {
    //     //问题规模N
    //     N = n[k];
    //     N = pow(2,N);
    //     f.open("..\\input\\input.txt",ios::in);
    //     for(int i = 0;i < N;i++)
    //     {
    //         f >> arr[i];
    //     }
    //     f.close();
    //     start = clock();
    //     insert_sort<int>(arr,N);
    //     end = clock();
    //     f.open("..\\output\\insert_sort\\time.txt",ios::out|ios::app);
    //     f << setprecision(10) << (end - start)/CLK_TCK << '\n';
    //     f.close();
    //     switch (k)
    //     {
    //         case(0):
    //             f.open("..\\output\\insert_sort\\result_3.txt",ios::out);
    //             break;
    //         case(1):
    //             f.open("..\\output\\insert_sort\\result_6.txt",ios::out);
    //             break;
    //         case(2):
    //             f.open("..\\output\\insert_sort\\result_9.txt",ios::out);
    //             break;
    //         case(3):
    //             f.open("..\\output\\insert_sort\\result_12.txt",ios::out);
    //             break;
    //         case(4):
    //             f.open("..\\output\\insert_sort\\result_15.txt",ios::out);
    //             break;
    //         case(5):
    //             f.open("..\\output\\insert_sort\\result_18.txt",ios::out);
    //             break;
    //         default:
    //             break;
    //     }
    //     for(int i = 0;i < N;i++)
    //     {
    //         f << arr[i] << '\n';
    //     }
    //     f.close();
    // }

    f.open("..\\output\\heap_sort\\time.txt",ios::out|ios::trunc);//先清空内容
    f.close();
    for(int k = 0;k < 6;k++)
    {
        //问题规模N = 5
        N = n[k];
        N = pow(2,N);
        f.open("..\\input\\input.txt",ios::in);
        for(int i = 0;i < N;i++)
        {
            f >> arr[i];
        }
        f.close();
        start = clock();
        heap_sort<int>(arr,N);
        end = clock();
        f.open("..\\output\\heap_sort\\time.txt",ios::out|ios::app);
        f << setprecision(10) << (end - start)/CLK_TCK << '\n';
        f.close();
        switch (k)
        {
            case(0):
                f.open("..\\output\\heap_sort\\result_3.txt",ios::out);
                break;
            case(1):
                f.open("..\\output\\heap_sort\\result_6.txt",ios::out);
                break;
            case(2):
                f.open("..\\output\\heap_sort\\result_9.txt",ios::out);
                break;
            case(3):
                f.open("..\\output\\heap_sort\\result_12.txt",ios::out);
                break;
            case(4):
                f.open("..\\output\\heap_sort\\result_15.txt",ios::out);
                break;
            case(5):
                f.open("..\\output\\heap_sort\\result_18.txt",ios::out);
                break;
            default:
                break;
        }
        for(int i = 0;i < N;i++)
        {
            f << arr[i] << '\n';
        }
        f.close();
    }

    f.open("..\\output\\quick_sort\\time.txt",ios::out|ios::trunc);//先清空内容
    f.close();
    for(int k = 0;k < 6;k++)
    {
        //问题规模N
        N = n[k];
        N = pow(2,N);
        f.open("..\\input\\input.txt",ios::in);
        for(int i = 0;i < N;i++)
        {
            f >> arr[i];
        }
        f.close();
        start = clock();
        quick_sort<int>(arr,0,N-1);
        end = clock();
        f.open("..\\output\\quick_sort\\time.txt",ios::out|ios::app);
        f << setprecision(10) << (end - start)/CLK_TCK << '\n';
        f.close();
        switch (k)
        {
            case(0):
                f.open("..\\output\\quick_sort\\result_3.txt",ios::out);
                break;
            case(1):
                f.open("..\\output\\quick_sort\\result_6.txt",ios::out);
                break;
            case(2):
                f.open("..\\output\\quick_sort\\result_9.txt",ios::out);
                break;
            case(3):
                f.open("..\\output\\quick_sort\\result_12.txt",ios::out);
                break;
            case(4):
                f.open("..\\output\\quick_sort\\result_15.txt",ios::out);
                break;
            case(5):
                f.open("..\\output\\quick_sort\\result_18.txt",ios::out);
                break;
            default:
                break;
        }
        for(int i = 0;i < N;i++)
        {
            f << arr[i] << '\n';
        }
        f.close();
    }

    f.open("..\\output\\merge_sort\\time.txt",ios::out|ios::trunc);//先清空内容
    f.close();
    for(int k = 0;k < 6;k++)
    {
        //问题规模N
        N = n[k];
        N = pow(2,N);
        f.open("..\\input\\input.txt",ios::in);
        for(int i = 0;i < N;i++)
        {
            f >> arr[i];
        }
        f.close();
        start = clock();
        merge_sort<int>(arr,0,N-1);
        end = clock();
        f.open("..\\output\\merge_sort\\time.txt",ios::out|ios::app);
        f << setprecision(10) << (end - start)/CLK_TCK << '\n';
        f.close();
        switch (k)
        {
            case(0):
                f.open("..\\output\\merge_sort\\result_3.txt",ios::out);
                break;
            case(1):
                f.open("..\\output\\merge_sort\\result_6.txt",ios::out);
                break;
            case(2):
                f.open("..\\output\\merge_sort\\result_9.txt",ios::out);
                break;
            case(3):
                f.open("..\\output\\merge_sort\\result_12.txt",ios::out);
                break;
            case(4):
                f.open("..\\output\\merge_sort\\result_15.txt",ios::out);
                break;
            case(5):
                f.open("..\\output\\merge_sort\\result_18.txt",ios::out);
                break;
            default:
                break;
        }
        for(int i = 0;i < N;i++)
        {
            f << arr[i] << '\n';
        }
        f.close();
    }


    f.open("..\\output\\counting_sort\\time.txt",ios::out|ios::trunc);//先清空内容
    f.close();
    for(int k = 0;k < 6;k++)
    {
        //问题规模N
        N = n[k];
        N = pow(2,N);
        f.open("..\\input\\input.txt",ios::in);
        for(int i = 0;i < N;i++)
        {
            f >> arr[i];
        }
        f.close();
        start = clock();
        counting_sort_less<int>(arr,N);
        end = clock();
        f.open("..\\output\\counting_sort\\time.txt",ios::out|ios::app);
        f << setprecision(10) << (end - start)/CLK_TCK << '\n';
        f.close();
        switch (k)
        {
            case(0):
                f.open("..\\output\\counting_sort\\result_3.txt",ios::out);
                break;
            case(1):
                f.open("..\\output\\counting_sort\\result_6.txt",ios::out);
                break;
            case(2):
                f.open("..\\output\\counting_sort\\result_9.txt",ios::out);
                break;
            case(3):
                f.open("..\\output\\counting_sort\\result_12.txt",ios::out);
                break;
            case(4):
                f.open("..\\output\\counting_sort\\result_15.txt",ios::out);
                break;
            case(5):
                f.open("..\\output\\counting_sort\\result_18.txt",ios::out);
                break;
            default:
                break;
        }
        for(int i = 0;i < N;i++)
        {
            f << arr[i] << '\n';
        }
        f.close();
    }
    return 0;
}