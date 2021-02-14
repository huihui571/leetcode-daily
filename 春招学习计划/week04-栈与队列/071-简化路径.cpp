/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 071-简化路径.cpp 
*   Author      : huihui571
*   Created date: 2021-02-09
*   Description : 给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。
*   在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，'//'）都被视为单个斜杠 '/' 。 对于此问题，任何其他格式的点（例如，'...'）均被视为文件/目录名称。
*   请注意，返回的 规范路径 必须遵循下述格式：
*       始终以斜杠 / 开头。
*       两个目录名之间必须只有一个斜杠 /。
*       最后一个目录名（如果存在）不能 以 / 结尾。
*       此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
*   返回简化后得到的 规范路径 。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 妙用stringstream和getline分割字符串
 * 以'/'分割后的字符串有4种情况：""，"."，".."，"abc"，其中遇到为空和.则什么也不用做，
 * 遇到abc这样的路径则将其入栈，遇到..则出栈回退路径。
 */
class Solution {
public:
    string simplifyPath(string path) {
        istringstream is(path);
        vector<string> st;      //用vector模拟栈，在最后连接结果字符串时比较方便
        string tmp;

        while (getline(is, tmp, '/')) {
            if (tmp == "" || tmp == ".") {
                continue;       //为空或.则什么也不做
            }
            else if (tmp == "..") {
                if (!st.empty()) {
                    st.pop_back();       //遇到..则退栈，注意栈不能为空
                }
            }
            else {
                st.push_back(tmp);   //其它字符则入栈
            }
        }

        string res;
        for (string str : st) {
            res += "/" + str;
        }
        return res == "" ? "/" : res;
    }
};
