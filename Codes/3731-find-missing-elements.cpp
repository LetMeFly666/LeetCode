/*
 * @Author: LetMeFly
 * @Date: 2026-08-04 11:01:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-04 11:04:35
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> ma(101);
        int m = nums[0], M = nums[0];
        for (int t : nums) {
            m = min(m, t);
            M = max(M, t);
            ma[t] = true;
        }
        
        vector<int> ans;
        ans.reserve(M - m + 1 - nums.size());
        for (int i = m + 1; i < M; i++) {
            if (!ma[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
