/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 1122-数组的相对排序.cpp
*   Author      : huihui571
*   Created date: 2020-11-05
*   Description : 给你两个数组，arr1 和 arr2，
    arr2 中的元素各不相同
    arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

#if 0
/**
 * 计数排序，很巧妙
 * 排成绩，先统计考每个分数(arr1)的同学有多少个，然后根据分数先后要求(arr2)取出进行排序即可
 */
class Solution
{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        int count[1001] = {0};
        //将arr1中的数记录下来
        for (int num1 : arr1)
        {
            count[num1]++;
        }
        //按照arr2的顺序安排
        int i = 0;
        for (int num2 : arr2)
        {
            while (count[num2] > 0)
            {
                arr1[i++] = num2;       //往里填符合要求的同学
                count[num2]--;          //这个分数的同学减一
            }
        }
        //再排剩下的同学
        for (int num1 = 0; num1 < 1001; num1++)
        {
            while (count[num1] > 0)
            {
                arr1[i++] = num1;
                count[num1]--;
            }
        }

        return arr1;
    }
};
#endif

#if 1
/**
 * 自定义比较函数，然后可以调用系统排序或者自己写其它排序方式
 * num1和num2的大小分三种情况:
 *     1. 都存在与arr2中，则下标小的更小
 *     2. 一个在一个不在，则在的更小
 *     3. 两个都不在，则按照实际数值比较大小
 * 用一个哈希表可以快速查询在arr2中的下标。
 */
//这里compare可以定义为静态成员函数或者普通全局函数，但静态成员函数引用成员变量hash_map又会出问题
//hash_map由于和传入参数有关每个对象实例都不一样，所以又不能定义成静态的
//所以都放在外部，每次记得把哈希表clear，以免影响下一次调用。
unordered_map<int, int> hash_map;
//返回num1是否小于num2
bool compare(int num1, int num2)
{
    if (hash_map.count(num1) && hash_map.count(num2))
        return hash_map.at(num1) < hash_map.at(num2);
    else if (hash_map.count(num1))
        return true;
    else if (hash_map.count(num2))
        return false;
    else
        return num1 < num2;
}
class Solution
{ 
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        for (int i = 0; i < arr2.size(); ++i)
        {
            hash_map.insert(make_pair(arr2[i], i));
        }

        sort(arr1.begin(), arr1.end(), compare);    //compare这函数指针不能用非静态成员函数，因为成员函数有this指针，与普通函数指针是不一样的。
        hash_map.clear();        //清理哈希表，以免影响下一次调用

        return arr1;
    }
};
#endif