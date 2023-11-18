/*
 * @Author: LetMeFly
 * @Date: 2023-11-18 11:18:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-18 11:22:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

inline int getSum(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> ma;
        int ans = -1;
        for (int t : nums) {
            int s = getSum(t);
            if (t > ma[s].second) {
                ma[s].second = t;
            }
            if (ma[s].first < ma[s].second) {
                swap(ma[s].first, ma[s].second);
            }
            if (ma[s].second) {
                ans = max(ans, ma[s].first + ma[s].second);
            }
        }
        return ans;
    }
};