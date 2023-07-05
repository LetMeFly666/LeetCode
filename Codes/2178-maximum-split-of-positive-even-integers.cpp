/*
 * @Author: LetMeFly
 * @Date: 2023-07-06 07:41:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-06 07:44:35
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    vector<ll> maximumEvenSplit(ll finalSum) {
        if (finalSum % 2) {
            return {};
        }
        vector<ll> ans;
        ll now = 2;
        while (finalSum - now > now) {
            ans.push_back(now);
            finalSum -= now;
            now += 2;
        }
        ans.push_back(finalSum);
        return ans;
    }
};