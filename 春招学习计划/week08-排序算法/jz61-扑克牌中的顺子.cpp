/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : jz61-扑克牌中的顺子.cpp
*   Author      : huihui571
*   Created date: 2021-03-16
*   Description : 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，
*   而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 首先顺子中不能有重复，所以先排序然后去重。由于大小王可以替代任何牌，所以先统计大小王的个数，
 * 然后剩下的牌如果最大值-最小值<5则可以成为顺子，否则不行。
 * Note：也可以先统计大小王的数量，然后用大小王去填充剩下不连续的部分，若能填充则是顺子。
 */
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        //排序后大小王一定出现在前面
        for (int i = 0; i < 4; ++i) {
            if (nums[i] == 0)
                count++;
            else if (nums[i] == nums[i + 1])
                return false;   //有重复提前返回
        }
        return nums[4] - nums[count] < 5;
    }
};

