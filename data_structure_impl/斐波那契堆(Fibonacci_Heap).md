## 斐波那契堆(Fibonacci Heap)
为了支持对两个堆进行合并的操作所引入；
一系列具有**最小堆序**的有根树的集合
### 可合并堆(Mergeable Heap)
#### 支持的操作
`Make_Heap();`返回一个空堆；
`Insert(H,x);`将元素x插入堆H中；
`Minimum(H);`返回堆H中最小的元素；
`Extract_Min(H);`删除堆H中最小的元素；
`Union(H1,H2);`合并堆H1和H2；

#### 斐波那契堆额外支持的操作
`Decrease_Key(H,x,k);`将堆H中x元素的关键字赋予新值k；
`Delete(H,x);`删除堆H中x元素；