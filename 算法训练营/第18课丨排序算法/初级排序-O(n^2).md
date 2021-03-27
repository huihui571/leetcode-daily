# 初级排序

## 选择排序
座位视角，给每个座位找人。
```
for (i = 0; i < len -1; i++)
{
    min_index = i;
    for (j = i + 1; j < len; j++)
    {
        if (arr[j] < arr[min_index])
            min_index = j;          //记下最小值索引
    }
    swap(arr[i], arr[min_index]);
}
return arr;
```

## 插入排序
同学视角，把每个人往前面已经排好的队里插。
```
for (i = 1; i < len； i++)
{
    cur = arr[i];
    j = i - 1;
    while (j >= 0 && cur < a[j])
    {
        a[j + 1] = a[j];        //依次后移，给cur腾出插入位置
        j--;
    }
    arr[j + 1] = cur;       //插入
}
return arr;
```

## 冒泡排序
相邻两两交换。
```
for (i = 0; i < len； i++)
{
    flag = false;
    for (j = len - 1; j > i; j--)
    {
        if (arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            flag = true;
        }
    }
    if (!flag)
        return arr;
}
```