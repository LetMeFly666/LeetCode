/*
 * @Author: LetMeFly
 * @Date: 2022-07-04 22:06:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-04 22:07:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int m = arr[1] - arr[0];
        for (int i = 1; i < arr.size(); i++) {
            m = min(m, arr[i] - arr[i - 1]);
        }
        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == m) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};