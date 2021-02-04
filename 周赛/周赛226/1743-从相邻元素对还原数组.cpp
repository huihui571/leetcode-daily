/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 1743-从相邻元素对还原数组.cpp 
*   Author      : huihui571
*   Created date: 2021-02-01
*   Description : 存在一个由 n 个不同元素组成的整数数组 nums ，但你已经记不清具体内容。好在你还记得 nums 中的每一对相邻元素。
*   给你一个二维整数数组 adjacentPairs ，大小为 n - 1 ，其中每个 adjacentPairs[i] = [ui, vi] 表示元素 ui 和 vi 在 nums 中相邻。
*   题目数据保证所有由元素 nums[i] 和 nums[i+1] 组成的相邻元素对都存在于 adjacentPairs 中，存在形式可能是 [nums[i], nums[i+1]] ，也可能是 [nums[i+1], nums[i]] 。这些相邻元素对可以 按任意顺序 出现。
*   返回 原始数组 nums 。如果存在多种解答，返回 其中任意一个 即可。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 用哈希表来保存连接关系。连接关系建立完成后，起点和终点只有一个连接而其它有两个。
 * 从起点或终点开始，沿着哈希表遍历即可输出。中间要考虑去重，已经添加到结果中的不要再添加。
 */
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> res;
        unordered_map<int, vector<int>> dict;

        //保存连接
        for (const auto& adj : adjacentPairs) {
            dict[adj[0]].push_back(adj[1]);
            dict[adj[1]].push_back(adj[0]);
        }

        // 找只有一个连接的端点
        int start = 1;
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            if (it->second.size() == 1) {
                start = it->first;
                break;
            }
        }

        //构建数组
        int pre = start;
        int cur = dict[start][0];
        res.push_back(pre);
        res.push_back(cur);
        while (res.size() != adjacentPairs.size() + 1) {
            for (auto next : dict[cur]) {
                if (next != pre) {      //避免重复只需要不回头就行了，这里也可以用Set，但是不如这样巧妙。
                    res.push_back(next);
                    pre = cur;
                    cur = next;
                    break;      //每个for其实只执行一次，找到next之后就跳到下一个
                }
            } 
        }

        return res;
    }
};

