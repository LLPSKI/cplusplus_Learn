#include<iostream>
#include<fstream>
#include<cmath>
#include<ctime>
#include<windows.h>
#include<chrono>
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
    // double start,end;
    // chrono::duration<double> duration;
    // double run_time;
    // _LARGE_INTEGER time_start,time_over;
    // LARGE_INTEGER f;
    // QueryPerformanceFrequency(&f);
    // double freq = (double)f.QuadPart;


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
    //     auto start = chrono::high_resolution_clock::now();
    //     insert_sort<int>(arr,N);
    //     auto end = chrono::high_resolution_clock::now();
    //     chrono::duration<double> duration = end - start;
    //     if(k < 3)
    //     {
    //         for(int i = 0;i < 9999;i++)
    //         {
    //             f.open("..\\input\\input.txt",ios::in);
    //             for(int i = 0;i < N;i++)
    //             {
    //                 f >> arr[i];
    //             }
    //             f.close();
    //             start = chrono::high_resolution_clock::now();
    //             insert_sort<int>(arr,N);
    //             end = chrono::high_resolution_clock::now();
    //             duration += end - start;
    //         }
    //         f.open("..\\output\\insert_sort\\time.txt",ios::out|ios::app);
    //         f << setprecision(6) << fixed << duration.count() << '\n';
    //         f.close();
    //     }
    //     else
    //     {
    //         f.open("..\\output\\insert_sort\\time.txt",ios::out|ios::app);
    //         f << setprecision(6) << fixed << duration.count()*10000.0 << '\n';
    //         f.close();
    //     }
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
    // cout << "insert_sort completed!\n";

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
        auto start = chrono::high_resolution_clock::now();
        heap_sort<int>(arr,N);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        if(k < 4)
        {
            for(int i = 0;i < 9999;i++)
            {
                f.open("..\\input\\input.txt",ios::in);
                for(int i = 0;i < N;i++)
                {
                    f >> arr[i];
                }
                f.close();
                start = chrono::high_resolution_clock::now();
                heap_sort<int>(arr,N);
                end = chrono::high_resolution_clock::now();
                duration += end - start;
            }
            f.open("..\\output\\heap_sort\\time.txt",ios::out|ios::app);
            f << setprecision(6) << fixed << duration.count() << '\n';
            f.close();
        }
        else
        {
            f.open("..\\output\\heap_sort\\time.txt",ios::out|ios::app);
            f << setprecision(6) << fixed << duration.count()*10000.0 << '\n';
            f.close();
        }
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
    cout << "heap_sort completed!\n";

    // f.open("..\\output\\quick_sort\\time.txt",ios::out|ios::trunc);//先清空内容
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
    //     auto start = chrono::high_resolution_clock::now();
    //     quick_sort<int>(arr,0,N-1);
    //     auto end = chrono::high_resolution_clock::now();
    //     chrono::duration<double> duration = end - start;
    //     if(k < 4)
    //     {
    //         for(int i = 0;i < 9999;i++)
    //         {
    //             f.open("..\\input\\input.txt",ios::in);
    //             for(int i = 0;i < N;i++)
    //             {
    //                 f >> arr[i];
    //             }
    //             f.close();
    //             start = chrono::high_resolution_clock::now();
    //             quick_sort<int>(arr,0,N-1);
    //             end = chrono::high_resolution_clock::now();
    //             duration += end - start;
    //         }
    //         f.open("..\\output\\quick_sort\\time.txt",ios::out|ios::app);
    //         f << setprecision(6) << fixed << duration.count() << '\n';
    //         f.close();
    //     }
    //     else
    //     {
    //         f.open("..\\output\\quick_sort\\time.txt",ios::out|ios::app);
    //         f << setprecision(6) << fixed << duration.count()*10000.0 << '\n';
    //         f.close();
    //     }
    //     switch (k)
    //     {
    //         case(0):
    //             f.open("..\\output\\quick_sort\\result_3.txt",ios::out);
    //             break;
    //         case(1):
    //             f.open("..\\output\\quick_sort\\result_6.txt",ios::out);
    //             break;
    //         case(2):
    //             f.open("..\\output\\quick_sort\\result_9.txt",ios::out);
    //             break;
    //         case(3):
    //             f.open("..\\output\\quick_sort\\result_12.txt",ios::out);
    //             break;
    //         case(4):
    //             f.open("..\\output\\quick_sort\\result_15.txt",ios::out);
    //             break;
    //         case(5):
    //             f.open("..\\output\\quick_sort\\result_18.txt",ios::out);
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
    // cout << "quick_sort completed!\n";

    // f.open("..\\output\\merge_sort\\time.txt",ios::out|ios::trunc);//先清空内容
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
    //     auto start = chrono::high_resolution_clock::now();
    //     merge_sort<int>(arr,0,N-1);
    //     auto end = chrono::high_resolution_clock::now();
    //     chrono::duration<double> duration = end - start;
    //     if(k < 3)
    //     {
    //         for(int i = 0;i < 9999;i++)
    //         {
    //             f.open("..\\input\\input.txt",ios::in);
    //             for(int i = 0;i < N;i++)
    //             {
    //                 f >> arr[i];
    //             }
    //             f.close();
    //             start = chrono::high_resolution_clock::now();
    //             merge_sort<int>(arr,0,N-1);
    //             end = chrono::high_resolution_clock::now();
    //             duration += end - start;
    //         }
    //         f.open("..\\output\\merge_sort\\time.txt",ios::out|ios::app);
    //         f << setprecision(6) << fixed << duration.count() << '\n';
    //         f.close();
    //     }
    //     else
    //     {
    //         f.open("..\\output\\merge_sort\\time.txt",ios::out|ios::app);
    //         f << setprecision(6) << fixed << duration.count()*10000.0 << '\n';
    //         f.close();
    //     }
    //     switch (k)
    //     {
    //         case(0):
    //             f.open("..\\output\\merge_sort\\result_3.txt",ios::out);
    //             break;
    //         case(1):
    //             f.open("..\\output\\merge_sort\\result_6.txt",ios::out);
    //             break;
    //         case(2):
    //             f.open("..\\output\\merge_sort\\result_9.txt",ios::out);
    //             break;
    //         case(3):
    //             f.open("..\\output\\merge_sort\\result_12.txt",ios::out);
    //             break;
    //         case(4):
    //             f.open("..\\output\\merge_sort\\result_15.txt",ios::out);
    //             break;
    //         case(5):
    //             f.open("..\\output\\merge_sort\\result_18.txt",ios::out);
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
    // cout << "merge_sort completed!\n";

    // f.open("..\\output\\counting_sort\\time.txt",ios::out|ios::trunc);//先清空内容
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
    //     auto start = chrono::high_resolution_clock::now();
    //     counting_sort_less<int>(arr,N);
    //     auto end = chrono::high_resolution_clock::now();
    //     chrono::duration<double> duration = end - start;
    //     if(k < 6)
    //     {
    //         for(int i = 0;i < 9999;i++)
    //         {
    //             f.open("..\\input\\input.txt",ios::in);
    //             for(int i = 0;i < N;i++)
    //             {
    //                 f >> arr[i];
    //             }
    //             f.close();
    //             start = chrono::high_resolution_clock::now();
    //             counting_sort_less<int>(arr,N);
    //             end = chrono::high_resolution_clock::now();
    //             duration += end - start;
    //         }
    //         f.open("..\\output\\counting_sort\\time.txt",ios::out|ios::app);
    //         f << setprecision(6) << fixed << duration.count() << '\n';
    //         f.close();
    //     }
    //     else
    //     {
    //         f.open("..\\output\\counting_sort\\time.txt",ios::out|ios::app);
    //         f << setprecision(6) << fixed << duration.count()*10000.0 << '\n';
    //         f.close();
    //     }
    //     switch (k)
    //     {
    //         case(0):
    //             f.open("..\\output\\counting_sort\\result_3.txt",ios::out);
    //             break;
    //         case(1):
    //             f.open("..\\output\\counting_sort\\result_6.txt",ios::out);
    //             break;
    //         case(2):
    //             f.open("..\\output\\counting_sort\\result_9.txt",ios::out);
    //             break;
    //         case(3):
    //             f.open("..\\output\\counting_sort\\result_12.txt",ios::out);
    //             break;
    //         case(4):
    //             f.open("..\\output\\counting_sort\\result_15.txt",ios::out);
    //             break;
    //         case(5):
    //             f.open("..\\output\\counting_sort\\result_18.txt",ios::out);
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
    // cout << "counting_sort completed!\n";
    return 0;
}