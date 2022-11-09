/*
 * @Author: LetMeFly
 * @Date: 2022-10-22 12:30:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-22 12:33:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int ls = 0, lg = 0;
        for (; lg < g.size(); lg++) {
            while (ls <s.size() && s[ls] < g[lg])
                ls++;
            if (ls < s.size())
                ans++, ls++;
            else
                break;
        }
        return ans;
    }
};