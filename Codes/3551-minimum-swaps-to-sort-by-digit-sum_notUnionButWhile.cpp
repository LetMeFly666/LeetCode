/*
 * @Author: LetMeFly
 * @Date: 2026-10-17 16:31:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-17 19:08:54
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int getSum(int a) {
        int ans = 0;
        while (a) {
            ans += a % 10;
            a /= 10;
        }
        return ans;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> idxs(n);
        ranges::iota(idxs, 0);
        sort(idxs.begin(), idxs.end(), [this, &nums](const int& a, const int& b) {
            int sa = getSum(nums[a]);
            int sb = getSum(nums[b]);
            return sa == sb ? nums[a] < nums[b] : sa < sb;
        });
        // debug(idxs);

        int ans = nums.size();
        vector<bool> visited(n);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans--;
            }
            int x = i;
            while (!visited[x]) {
                visited[x] = true;
                x = idxs[x];
            }
        }
        return ans;
    }
};
