/*
 * @Author: LetMeFly
 * @Date: 2023-10-13 09:27:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-13 13:55:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> whenNotRain;
        unordered_map<int, int> whichAndWhen;
        vector<int> ans(rains.size(), 1);  // 没有0号湖
        for (int i = 0; i < rains.size(); i++) {
            if (!rains[i]) {
                whenNotRain.insert(i);
                continue;
            }
            ans[i] = -1;
            if (whichAndWhen.count(rains[i])) {
                int lastRainDay = whichAndWhen[rains[i]];  // 找一个lastRainDay后的晴天
                set<int>::iterator it = whenNotRain.upper_bound(lastRainDay);
                if (it == whenNotRain.end()) {
                    return {};
                }
                ans[*it] = rains[i];
                whenNotRain.erase(it);
            }
            whichAndWhen[rains[i]] = i;
        }
        return ans;
    }
};