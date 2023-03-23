/*
 * @Author: LetMeFly
 * @Date: 2023-03-23 17:00:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-23 17:08:52
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size());
        for (int i = 0; i < l.size(); i++) {
            int m = *min_element(nums.begin() + l[i], nums.begin() + r[i] + 1);
            int M = *max_element(nums.begin() + l[i], nums.begin() + r[i] + 1);
            if (m == M) {
                ans[i] = true;
                continue;
            }
            if ((M - m) % (r[i] - l[i])) {
                ans[i] = false;
                continue;
            }
            int d = (M - m) / (r[i] - l[i]);
            unordered_set<int> se;
            for (int j = l[i]; j <= r[i]; j++) {
                if (se.count(nums[j])) {
                    ans[i] = false;
                    goto loop;
                }
                if ((nums[j] - m) % d) {
                    ans[i] = false;
                    goto loop;
                }
                se.insert(nums[j]);
            }
            ans[i] = true;
            loop:;
        }
        return ans;
    }
};