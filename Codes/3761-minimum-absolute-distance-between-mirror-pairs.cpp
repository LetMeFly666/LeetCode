/*
 * @Author: LetMeFly
 * @Date: 2026-04-17 23:04:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-17 23:10:50
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

constexpr int inf = 1000000;
class Solution {
private:
    int reverse(int n) {
        int ans = 0;
        while (n) {
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> ma;
        int ans = inf;
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (ma.count(nums[i])) {
                ans = min(ans, i - ma[nums[i]]);
            }
            ma[reverse(nums[i])] = i;
        }
        return ans == inf ? -1 : ans;
    }
};
