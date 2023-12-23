#include<iostream>
#include<ctime>
#include<algorithm>
#include<cstring>
using namespace std;
#include"test"
#include"../data_structure_impl/heap_impl"

template<typename T>
struct bucket_node
{
    T value;
    bucket_node<T>* next;
    ~bucket_node()
    {
        if(this->next!=NULL)
        {
            delete this->next;
        }
    }
};
template<typename T,typename compare=less<T>>
void insert_sort(bucket_node<T>* b,T& value,const compare& comp=compare())
{
    if(b->next!=NULL)
    {
        while(comp(b->next->value,value))
        {
            b=b->next;
            if(b->next==NULL)
            {
                break;
            }
        }
        bucket_node<T>* new_node=new bucket_node<T>();
        new_node->next=b->next;
        b->next=new_node;
        new_node->value=value;
        new_node->next=NULL;
        return ;
    }
    b->next=new bucket_node<T>();
    b->next->value=value;
    b->next->next=NULL;
}
/*
归并排序算法
算法思想：
    分治法，排序一段序列等于排序左边序列和右边序列，然后将两个子序列合并。
时间复杂度：
    O(nlgn)，算比较可以的。
*/
template<typename T,typename compare=less<T>>
void merge(T*& arr,size_t low,size_t mid,size_t high,const compare& comp=compare())
{
	int i=low,j=mid+1,range=0;
	int *temp=new int[high-low+1];
	while(i<=mid&&j<=high)
	{
		if(comp(arr[i],arr[j]))
		{
			temp[range++]=arr[i++];
		}else 
		{
			temp[range++]=arr[j++];
		}
	}
	while(i<=mid) temp[range++]=arr[i++];
	while(j<=high) temp[range++]=arr[j++];
	for(int l=0;l<range;l++)
	{
		arr[l+low]=temp[l];
	}
    delete[] temp;
}
template<typename T,typename compare=less<T>>
void merge_sort(T*& arr,size_t low,size_t high,const compare& comp=compare())
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
void bubble_sort(T*& arr,size_t n,const compare& comp=compare())
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
template<typename T,typename compare=less<T>>
int partition(T*& arr,int low,int high,const compare& comp=compare())
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
void quick_sort(T*& arr,int low,int high,const compare& comp=compare())
{
	if(low<high)
	{
		int i=partition(arr,low,high,comp);
		quick_sort(arr,low,i-1,comp);
		quick_sort(arr,i+1,high,comp);
	}
}
/*
推排序算法
主要思想：
    利用（大）根堆这种数据结构对记录进行排序

*/
template<typename T,typename compare=greater<T>>
void heap_sort(T*& arr,size_t n,const compare& comp=compare())
{
    heap<T,compare>::build_heap(arr,n);
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heap<T,compare>::heapify(arr,0,i);
    }
}

//********************************************************************************************************
//非比较排序算法
/*
计数排序算法
主要算法思想：
    对于每一个元素x，记录比它大或小的元素个数，对应的便可以将其放在数组相应位置
时间复杂度：
    Θ(range+n)
缺点：
    一般来说，元素的范围很难确定，普遍已知的是元素的个数；如果元素的个数远大于元素本身的范围，那么算法会很优，但如果
元素的个数远小于元素本身的范围，那么会导致count数组很大，影响时间和空间复杂度；所以存在一定的限制
*/
template<typename T>
void counting_sort_less(T*& arr,size_t n,size_t range=RAND_MAX+1)//千万注意：range是个闭区间
{
    T* count=new T[range];
    memset(count,0,sizeof(T)*range);//将count数组初始化为0
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;//记录元素个数
    }
    for(int i=1;i<range;i++)
    {
        count[i]+=count[i-1];//记录小于该元素的格式
    }
    T* temp=new T[n];
    for(int i=n-1;i>=0;i--)
    {
        temp[count[arr[i]]-1]=arr[i];//将对应元素放在相应的位置，-1是数组下标以0开始
        count[arr[i]]--;//支持元素相异
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i];//将数据写回原数组
    }
    delete[] temp,count;
}
template<typename T>//基数排序所需使用的计数排序算法，range->base
void counting_sort_less(T*& arr,size_t n,size_t base,size_t digit)//digit表示对应的第几位，从1开始
{
    T *count=new T[base];
    T *temp=new T[n];
    memset(count,0,sizeof(T)*base);
    T mod1=1,mod2;
    for(int i=0;i<digit;i++)
    {
        mod2=mod1;
        mod1*=base;
    }
    for(int i=0;i<n;i++)
    {
        count[arr[i]%mod1/mod2]++;
    }
    for(int i=1;i<base;i++)
    {
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        temp[count[arr[i]%mod1/mod2]-1]=arr[i];
        count[arr[i]%mod1/mod2]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i];
    }
    delete[] temp,count;
}
template<typename T>
void counting_sort_greater(T*& arr,size_t n,size_t range=RAND_MAX+1)
{
    T *count=new T[range];
    T *temp=new T[n];
    memset(count,0,sizeof(T)*range);
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    for(int i=range-2;i>=0;i--)//从后面向前加，表示大于该元素的个数
    {
        count[i]+=count[i+1];
    }
    for(int i=n-1;i>=0;i--)
    {
        temp[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i];
    }
    delete[] temp,count;
}
template<typename T>
void counting_sort_greater(T*& arr,size_t n,size_t base,size_t digit)
{
    T *count=new T[base];
    T *temp=new T[n];
    memset(count,0,sizeof(T)*base);
    T mod1=1,mod2;
    for(int i=0;i<digit;i++)
    {
        mod2=mod1;
        mod1*=base;
    }
    for(int i=0;i<n;i++)
    {
        count[arr[i]%mod1/mod2]++;
    }
    for(int i=base-2;i>=0;i--)
    {
        count[i]+=count[i+1];
    }
    for(int i=n-1;i>=0;i--)
    {
        temp[count[arr[i]%mod1/mod2]-1]=arr[i];
        count[arr[i]%mod1/mod2]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i];
    }
    delete[] temp,count;
}

template<typename T>
void radix_sort_less(T*& arr,size_t n,size_t d,size_t base=10)
{
    for(int digit=1;digit<=d;digit++)
    {
        counting_sort_less(arr,n,base,digit);
    }
}
template<typename T>
void radix_sort_great(T*& arr,size_t n,size_t d,size_t base=10)
{
    for(int digit=1;digit<=d;digit++)
    {
        counting_sort_greater(arr,n,base,digit);
    }
}
/*
桶排序算法
主要思想：
    如果输入的数据具有在某一区间均匀分布的性质，例如在[0,range)区间上元素均匀分布，那么便可以设置t个桶，第i个桶（0≤i≤t-1）
中元素的范围是[i*(range/t),(i+1)*(range/t)-1]，将元素放在相应桶的位置之后，再对每一个桶进行简答插入排序，或者其实在插入桶的过程
中便执行插入排序，这样按序号顺序输出便是有序的记录；
缺点：
    限制比较大，和计数排序一样，至少需要知道元素大小的范围，然后对应设置桶的数量，且桶的数量t不能太少，太少执行插入排序
影响运行时间；太多影响空间复杂度；
时间复杂度：
    最好的情况可以是Θ(n)量级，就看怎么组织算法了；
*/
template<typename T,typename compare=less<T>>
void bucrangeet_sort(T*& arr,size_t n,size_t range=RAND_MAX,const compare& comp=compare(),size_t base=10)
{
    int t=range/base;//此时第i个桶(0≤i≤t-1)中元素的范围是[i*10,(i+1)*10-1]
    bucrangeet_node<T>* bucrangeet=new bucrangeet_node<T>[t];
    for(int i=0;i<t;i++)
    {
        bucrangeet[i].next=NULL;
    }
    for(int i=0;i<n;i++)
    {
        insert_sort(&bucrangeet[arr[i]/base],arr[i],comp);
    }
    bucrangeet_node<T>* p=NULL;
    for(int i=0,j=0;i<t;i++)
    {
        p=&bucrangeet[i];
        while(p->next!=NULL)
        {
            arr[j++]=p->next->value;
            p=p->next;
        }
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
    counting_sort_less(arr,n);
    end=clock();
    if(is_correct(arr,n))
    {
        cout<<"计数排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    radix_sort_less(arr,n,6);
    end=clock();
    if(is_correct(arr,n))
    {
        cout<<"基数排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    bucrangeet_sort(arr,n);
    end=clock();
    if(is_correct(arr,n))
    {
        cout<<"桶排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    sort(arr,arr+n);
    end=clock();
    if(is_correct(arr,n))
    {
        cout<<"系统（快速）排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    quicrange_sort(arr,0,n-1);
    end=clock();
    if(is_correct(arr,n))
    {
        cout<<"快速排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    heap_sort(arr,n);
    end=clock();
    if(is_correct(arr,n))
    {
        cout<<"堆排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    merge_sort(arr,0,n-1);
    end=clock();
    if(is_correct(arr,n))
    {
        cout<<"归并排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }
    
    upload(arr,n);
    start=clock();
    insert_sort(arr,n);
    end=clock();
    if(is_correct<int>(arr,n))
    {
        cout<<"插入排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    bubble_sort(arr,n);
    end=clock();
    if(is_correct<int>(arr,n))
    {
        cout<<"（交换）冒泡算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }
//********************************************************************************************************
    cout<<"\n逆序排序\n";
    upload(arr,n);
    start=clock();
    counting_sort_greater(arr,n);
    end=clock();
    if(is_correct(arr,n,greater<int>()))
    {
        cout<<"计数排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    radix_sort_great(arr,n,6);
    end=clock();
    if(is_correct(arr,n,greater<int>()))
    {
        cout<<"基数排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    sort(arr,arr+n,greater<int>());
    end=clock();
    if(is_correct(arr,n,greater<int>()))
    {
        cout<<"系统（快速）排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    quicrange_sort(arr,0,n-1,greater<int>());
    end=clock();
    if(is_correct(arr,n,greater<int>()))
    {
        cout<<"快速排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    heap_sort(arr,n,less<int>());
    end=clock();
    if(is_correct(arr,n,greater<int>()))
    {
        cout<<"堆排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    merge_sort(arr,0,n-1,greater<int>());
    end=clock();
    if(is_correct(arr,n,greater<int>()))
    {
        cout<<"归并排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }
    
    upload(arr,n);
    start=clock();
    insert_sort(arr,n,greater<int>());
    end=clock();
    if(is_correct<int>(arr,n,greater<int>()))
    {
        cout<<"插入排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }

    upload(arr,n);
    start=clock();
    bubble_sort(arr,n,greater<int>());
    end=clock();
    if(is_correct<int>(arr,n,greater<int>()))
    {
        cout<<"（交换）冒泡排序算法正确，";
        cout<<"运行时间："<<(end-start)/CLK_TCK<<'\n';
    }
    return 0;
}

