/*
 * @Author: LetMeFly
 * @Date: 2025-04-24 22:47:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-24 23:05:27
 * @Description: AC,36.08%,63.38%
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> visited;
        for (int t : nums) {
            visited.insert(t);
        }
        int allType = visited.size();
        unordered_map<int, int> times;
        int ans = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            times[nums[r]]++;
            while (times.size() == allType && times[nums[l]] > 1) {
                times[nums[l++]]--;
            }
            if (times.size() == allType) {
                ans += l + 1;
            }
        }
        return ans;
    }
};
