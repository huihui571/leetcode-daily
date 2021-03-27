/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 547-朋友圈.cpp
*   Author      : huihui571
*   Created date: 2020-10-19
*   Description : 班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。
给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。
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
#include <algorithm>

using namespace std;

/**
 * 并查集：用一个数组表示一个森林，每个元素parent指针指向其父元素，根节点parent指向自己。
 */
class UnionFind
{
private:
    int count;      //记录连通分量
    int* parent;    //是一个数组，节点x的父节点是parent[x]
public:
    /*构造函数*/
    UnionFind(int n)
    {
        this->count = n; //一开始互不连通
        parent = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;      //父节点指针初始指向自己
        }
    }

    /*返回某个节点的根节点*/
    int find_root(int x)
    {
        //根节点有parent[x] == x
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]];  //这一句进行路径压缩，将x提到和x的父亲并列的层级
            x = parent[x];
        }
        return x;
    }

    /*合并x,y所在的两棵树*/
    void union_tree(int x, int y)
    {
        int root_x = find_root(x);
        int root_y = find_root(y);

        if (root_x == root_y)
            return;

        parent[root_x] = root_y;  //把x挂到y上面去
        count--;                //连通分量-1
    }

    /*返回连通量个数*/
    int tree_count()
    {
        return this->count;
    }
};

class Solution
{
public:
    int findCircleNum(vector<vector<int>>& M) 
    {
        int n = M.size();
        UnionFind uf(n);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)     //对称矩阵，遍历一般就行了
            {
                if (M[i][j] == 1)
                {
                    uf.union_tree(i, j);    //两个节点相连，则合并
                }
            }
        }

        return uf.tree_count();
    }
};