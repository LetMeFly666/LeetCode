/*
 * @Author: LetMeFly
 * @Date: 2023-06-07 13:10:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-07 13:13:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<int> first(reward1.size());
        int ans = 0;
        for (int i = 0; i < reward1.size(); i++) {
            ans += reward2[i];
            first[i] = reward1[i] - reward2[i];
        }
        sort(first.begin(), first.end());
        while (k) {
            ans += first[first.size() - k--];
        }
        return ans;
    }
};