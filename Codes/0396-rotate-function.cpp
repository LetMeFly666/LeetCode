/*
 * @Author: LetMeFly
 * @Date: 2026-05-01 21:26:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-01 21:34:50
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        ll now = 0, sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            now += i * nums[i];
            sum += nums[i];
        }
        
        ll ans = now;
        for (int i = 1; i < n; i++) {
            now = now + sum - n * nums[n - i];
            ans = max(ans, now);
        }
        return ans;
    }
};
