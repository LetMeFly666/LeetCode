/*
 * @Author: LetMeFly
 * @Date: 2024-12-31 13:04:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-31 13:10:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), greater<>());
        sort(verticalCut.begin(), verticalCut.end(), greater<>());
        int hCutTime = 0, vCutTime = 0;
        ll ans = 0;
        while (hCutTime < horizontalCut.size() || vCutTime < verticalCut.size()) {
            if (vCutTime == verticalCut.size() || hCutTime < horizontalCut.size() && horizontalCut[hCutTime] > verticalCut[vCutTime]) {
                ans += horizontalCut[hCutTime++] * (vCutTime + 1);
            } else {
                ans += verticalCut[vCutTime++] * (hCutTime + 1);
            }
        }
        return ans;
    }
};