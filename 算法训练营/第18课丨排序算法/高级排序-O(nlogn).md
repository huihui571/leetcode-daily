# 高级排序

## 快速排序
数组取标杆pivot，将小元素放pivot左侧，大元素放右侧，然后依次对左边和右边的子数组进行快排；
```
void quickSort(int[] array, int begin, int end)
{
    if (end <= begin)
        return;

    int pivot = partition(array, begin, end);
    quickSort(array, begin, pivot - 1);
    quickSort(array, pivot + 1, end);
}

int partition(int[] a, int begin, int end)
{
    //piovt标杆位置，counter:小于pivot的元素的个数
    int pivot = end, counter = begin;
    for (int i = begin; i < end; i++)
    {
        if (a[i] < a[pivot])
        {
            swap(a[i], a[privot]);
            counter++;
        }
    }

    swap(a[pivot], a[counter]);
    
    return counter;
}
```

快排为什么不稳定？

单向partition在执行到最后一步的时候会将pivot所在的位置和left位置交换，right位置如果是相同的数就会被换到前面导致不稳定。
当要排序的内容是一个对象的多个数字属性，且其原本的顺序存在意义时，如果我们需要在二次排序后保持原有排序的意义，就需要使用稳定的排序算法。排序算法的稳定性与效率、可靠性都无关。

## 归并排序
1. 将数组分为两个长度为n/2的子序列
2. 对两个子序列分别采取归并排序
3. 将两个排好序的子序列合并成一个最终的有序序列
```
void mergeSort(int[] array, int left, int right)
{
    if (right <= left)
        return;

    int mid = (left + right) >> 1;

    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}
//合并两个有序数组，三个while模板
void merge(int[] arr, int left, int mid, int right)
{
    int[] res = new int[right - left + 1];
    int i = left, j = mid + 1; k = 0;

    while (i <= mid && j <= right)
    {
        res[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }

    while (i <= mid)   res[k++] = arr[i++];
    while (j <= right) res[k++] = arr[j++];

    for (int p = 0; p < res.length; p++) 
    {
        arr[left + p] = res[p];
    }
}
```

## 堆排序
每次插入删除O(n)，取最大/最小元素O(1)，整体O(nlogn)
1. 数组元素依次建立小顶堆
2. 依次取堆顶元素，并删除

```
void heap_sort(int a[], int len)
{
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < len; i++)
    {
        q.push(a[i]);
    }

    for (int i = 0; i < len; i++)
    {
        a[i] = q.pop();
    }
}
```
