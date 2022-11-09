/*
 * @Author: LetMeFly
 * @Date: 2022-09-03 21:00:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-03 21:02:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = 0;
        int lastEnd = INT_MIN;
        for (int i = 0; i < pairs.size(); i++) {
            if (pairs[i][0] > lastEnd) {
                lastEnd = pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};