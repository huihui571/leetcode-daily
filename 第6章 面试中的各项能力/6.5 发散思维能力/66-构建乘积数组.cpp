/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 66-构建乘积数组.cpp
*   Author      : huihui571
*   Created date: 2021-01-18
*   Description : 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
*   其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。
*   不能使用除法。
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
 * 限制不能用除法，否则用所有数的乘积除以对应的A[i]即得B[i].
 * 对每个B[i]按题意去乘，有大量的重复运算，时间复杂度将是O(n2)
 * 将B[i]拆成L[i]=A[0]xA[1]x...xA[i-1]与R[i]=A[i+1]x...xA[n-1]两部分，则B[i]=L[i]xR[i]
 * 这样L[i]和R[i]可分别递推计算，即动态规划思路。
 * dp数组：L[i]表示A前i个元素乘积，R[i]表示A后i个元素的乘积。
 */
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.empty()) return a;

        int len = a.size();
        vector<int> B(len, 1);
        vector<int> L(len, 1);
        vector<int> R(len, 1);

        //递推计算L[],R[]
        L[0] = 1;
        for (int i = 1; i < len; ++i)
        {
            L[i] = L[i - 1] * a[i - 1];
        }

        R[len - 1] = 1;
        for (int i = len - 2; i >= 0; --i)
        {
            R[i] = R[i + 1] * a[i + 1];
        }

        //计算B[]
        for (int i = 0; i < len; ++i)
        {
            B[i] = L[i] * R[i];
        }
        return B;
    }
};
#endif

#if 1
/**
 * 空间优化。L，R数组每次只用到了i-1的状态，所以可以用一个变量记录当前乘积。
 */
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.empty()) return a;

        int len = a.size();
        vector<int> B(len, 1);
        int left = 1, right = 1;
        B[0] = 1;

        for (int i = 1; i < len; ++i)
        {
            // B[i] = B[i - 1] * a[i - 1];
            left *= a[i - 1];
            B[i] *= left;
        }
        for (int i = len - 2; i >= 0; --i)
        {
            right *= a[i + 1];
            B[i] *= right;
        }

        return B;
    }
};
#endif

