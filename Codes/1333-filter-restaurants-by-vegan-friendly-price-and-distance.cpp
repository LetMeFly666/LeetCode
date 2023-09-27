/*
 * @Author: LetMeFly
 * @Date: 2023-09-27 18:55:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-27 19:05:05
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> temp;
        for (auto&& v : restaurants) {
            if (v[2] >= veganFriendly && v[3] <= maxPrice && v[4] <= maxDistance) {
                temp.push_back(v);
            }
        }
        sort(temp.begin(), temp.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
        });
        vector<int> ans;
        for (auto&& v : temp) {
            ans.push_back(v[0]);
        }
        return ans;
    }
};