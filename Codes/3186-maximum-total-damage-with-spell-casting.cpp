/*
 * @Author: LetMeFly
 * @Date: 2025-10-11 18:10:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-11 18:33:47
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#include <algorithm>
#endif

typedef long long ll;
class Solution {
public:
    ll maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> cnt;
        for (int t : power) {
            cnt[t]++;
        }
        vector<pair<int, int>> values(cnt.begin(), cnt.end());
        std::ranges::sort(values);
        return 0;
    }
};
