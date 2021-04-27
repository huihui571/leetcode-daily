/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : filename
*   Author      : huihui571
*   Created date: 2021-04-25
*   Description : 
*
*<FH->***************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 滑动窗口
 */
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector<char> window; 
        unordered_set<char> cnt;
        int res = 0;

        int left = 0, right = 0;

        while (right < word.length()) {
            //窗口右扩
            if (window.empty() || word[right] >= window.back()) {
                window.push_back(word[right]);
                cnt.insert(word[right]);
                // cout << "right: " << right << " win: " << window.size() << " cnt: " << cnt.size()<<endl;
                
                //满足条件，记录答案
                if (cnt.size() == 5) {
                    res = max(res, (int)window.size());
                }
            }
            //窗口左侧收缩
            else {
                // cout << "clear at right= " << right << endl; 
                window.clear();
                cnt.clear();
                left = right;
                window.push_back(word[left]);
                cnt.insert(word[left]);
            }
            right++;
        }

        return res;
    }
};

