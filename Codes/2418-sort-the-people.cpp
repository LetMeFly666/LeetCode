/*
 * @Author: LetMeFly
 * @Date: 2023-04-25 20:37:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-25 20:38:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> a(names.size());
        for (int i = 0; i < names.size(); i++) {
            a[i] = {-heights[i], names[i]};
        }
        sort(a.begin(), a.end());
        vector<string> ans(a.size());
        for (int i = 0; i < a.size(); i++) {
            ans[i] = a[i].second;
        }
        return ans;
    }
};