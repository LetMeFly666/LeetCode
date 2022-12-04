/*
 * @Author: LetMeFly
 * @Date: 2022-12-04 11:18:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-04 12:37:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


#ifdef FirstTry  // Error  // 是0、1、2 种 配料，不是0、1、2 个 配料
#define update(total)                             \
    if (abs(total - target) < mDiff) {            \
        mDiff = abs(total - target), ans = total; \
    }

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int mDiff = 1e8, ans = baseCosts[0];
        int n = baseCosts.size(), m = toppingCosts.size();
        for (int i = 0; i < n; i++) {
            int total = baseCosts[i];
            update(total);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int total = baseCosts[i] + toppingCosts[j];
                update(total);
            }
        }
        // 中断
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // Copy
class Solution {
public:
    int closestCost(vector<int>& base, vector<int>& top, int V) {
        vector<bool> dp(V + 5);
        int ans = 0x3f3f3f3f;
        for (int x : base) { //判断只能选基料
            if (x > V) ans = min(ans, x);
            else dp[x] = true;
        }
        for (int x : top) {
            for (int i = 0; i < 2; i++) { //选2次
                for (int j = V; j >= 0; j--) { 
                    if (dp[j] && j + x > V) ans = min(ans, j + x); //计算大于的情况
                    if (j > x) dp[j] = dp[j] | dp[j - x];
                }
            }
        }
        //ans-V:目前获得与target的差距 
        for (int i = 0; i <= ans - V && i <= V; i++) if (dp[V - i]) return V - i;
        return ans;
    }
};
#endif  // FirstTry