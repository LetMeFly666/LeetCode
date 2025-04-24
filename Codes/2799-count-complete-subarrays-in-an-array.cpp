/*
 * @Author: LetMeFly
 * @Date: 2025-04-24 22:47:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-24 23:02:24
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
            while (times.size() == allType) {
                if (!--times[nums[l]]) {
                    times.erase(nums[l++]);
                }
            }
        }
        return ans;
    }
};
