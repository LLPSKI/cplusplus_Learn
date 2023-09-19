#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;
#include"test"
/*
插入排序算法
算法思想：
    让一个序列从第一个开始一点一点有序，每次将有序最外面的那个元素插入到有序序列中的相应位置，同时保证有序序列仍然有序，
直到整个序列有序。
时间复杂度：
    狗都不用，最好情况O(n)，而且概率极低，平均和最坏情况都是O(n2)，基本上没法用。
*/
template<typename T,typename compare=less<T>>
void insert_sort(T* arr,int n,const compare& comp=compare())
{
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        for(int j=i-1;j>=0;j--)
        {
            if(comp(temp,arr[j]))
            {
                arr[j+1]=arr[j];
                continue;
            }
            arr[j+1]=temp;
            break;
        }
    }
}
/*
归并排序算法
算法思想：
    分治法，排序一段序列等于排序左边序列和右边序列，然后将两个子序列合并。
时间复杂度：
    O(nlgn)，算比较可以的。
*/
template<typename T,typename compare=less<T>>
void merge(T *arr,int low,int mid,int high,const compare& comp=compare())
{
	int i=low,j=mid+1,k=0;
	int *temp=new int[high-low+1];
	while(i<=mid&&j<=high)
	{
		if(comp(arr[i],arr[j]))
		{
			temp[k++]=arr[i++];
		}else 
		{
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid) temp[k++]=arr[i++];
	while(j<=high) temp[k++]=arr[j++];
	for(int l=0;l<k;l++)
	{
		arr[l+low]=temp[l];
	}
}
template<typename T,typename compare=less<T>>
void merge_sort(T *arr,int low,int high,compare comp=compare())
{
	if(low<high)
	{
		int mid=(low+high)/2;
		merge_sort(arr,low,mid,comp);
		merge_sort(arr,mid+1,high,comp);
		merge(arr,low,mid,high,comp);
	}
}
/*
交换排序算法
主要思想：
	两两比较待排序记录的关键字，如果不满足次序要求，则两两交换，直到整个序列全部满足要求为止； 

1.冒泡排序算法
算法思想：
	每一趟冒泡排序就相当于将最大的那个记录移到对应的最后一个位置；
优化：
    设置一个标志记录一趟排序下来序列是否存在变化，可以避免重复比较，以优化算法；(事实证明优化没啥用) 
	最好的情况（记录基本符合要求-正序）：O(n)；最坏的情况需要进行n-1趟排序，平方阶； 

2.快速排序
算法思想：
	冒泡排序中每次交换只会消除一个逆序序列，而快速排序则可以一次交换消除多个逆序系列；每一趟排序都将序列分为两部分，一部
分小于中间值的放左边，另一部分放右边，最后再递归处理左子序列和右子序列； 
*/
template<typename T,typename compare=less<T>>
void bubble_sort(T *arr,int n,const compare& comp=compare())
{
	int flag=1;
	while(n>0&&flag==1)
	{
		flag=0;
		for(int i=0;i<n-1;i++)
		{
			if(comp(arr[i+1],arr[i]))
			{
				flag=1;
				int temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
		n--;
	}
}
int cnt=0;
template<typename T,typename compare=less<T>>
int partition(T* arr,int low,int high,const compare& comp=compare())
{
	int i=low;
	int temp=arr[high];
	for(int j=low;j<=high;j++)
	{
		if(comp(arr[j],temp))
		{
			swap(arr[j],arr[i]);
			i++;
		}
	}
	swap(arr[i],arr[high]);
	return i;
}
template<typename T,typename compare=less<T>>
void quick_sort(T* arr,int low,int high,const compare& comp=compare())
{
	if(low<high)
	{
		int i=partition(arr,low,high,comp);
		quick_sort(arr,low,i-1,comp);
		quick_sort(arr,i+1,high,comp);
	}
}

int main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int *arr=new int[n];
    double start,end;

//********************************************************************************************************
    cout<<"正序排序\n";
    upload(arr,n);
    start=clock();
    sort(arr,arr+n);
    end=clock();
    if(is_correct(arr,n))
    {
        cout<<"系统（快速）排序算法正确\n";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    quick_sort(arr,0,n-1);
    end=clock();
    if(is_correct(arr,n))
    {
        cout<<"快速排序算法正确\n";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    merge_sort(arr,0,n-1);
    end=clock();
    if(is_correct(arr,n))
    {
        cout<<"归并排序算法正确\n";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }
    
    upload(arr,n);
    start=clock();
    insert_sort(arr,n);
    end=clock();
    if(is_correct<int>(arr,n))
    {
        cout<<"插入排序算法正确\n";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    bubble_sort(arr,n);
    end=clock();
    if(is_correct<int>(arr,n))
    {
        cout<<"（交换）冒泡算法正确\n";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }
//********************************************************************************************************
    cout<<"\n逆序排序\n";
    upload(arr,n);
    start=clock();
    sort(arr,arr+n,greater<int>());
    end=clock();
    if(is_correct(arr,n,greater<int>()))
    {
        cout<<"系统（快速）排序算法正确\n";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    quick_sort(arr,0,n-1,greater<int>());
    end=clock();
    if(is_correct(arr,n,greater<int>()))
    {
        cout<<"快速排序算法正确\n";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    merge_sort(arr,0,n-1,greater<int>());
    end=clock();
    if(is_correct(arr,n,greater<int>()))
    {
        cout<<"归并排序算法正确\n";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }
    
    upload(arr,n);
    start=clock();
    insert_sort(arr,n,greater<int>());
    end=clock();
    if(is_correct<int>(arr,n,greater<int>()))
    {
        cout<<"插入排序算法正确\n";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    bubble_sort(arr,n,greater<int>());
    end=clock();
    if(is_correct<int>(arr,n,greater<int>()))
    {
        cout<<"（交换）冒泡排序算法正确\n";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }
    return 0;
}

