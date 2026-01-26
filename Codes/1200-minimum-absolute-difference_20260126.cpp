/*
 * @Author: LetMeFly
 * @Date: 2026-01-26 23:38:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-26 23:39:44
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int mini = 10000001;
        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            if (diff == mini) {
                ans.push_back({arr[i - 1], arr[i]});
            } else if (diff < mini) {
                mini = diff;
                ans = {{arr[i - 1], arr[i]}};
            }
        }
        return ans;
    }
};