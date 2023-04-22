/*
 * @Author: LetMeFly
 * @Date: 2023-04-22 09:42:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-22 09:47:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 2;
        auto minmax = minmax_element(nums.begin(), nums.end());
        int diff = *minmax.second - *minmax.first;
        for (int d = -diff; d <= diff; d++) {  // 要从-diff开始
            unordered_map<int, int> ma;
            for (int num : nums) {
                int thisAns;
                if (ma.count(num - d)) {
                    thisAns = ma[num - d] + 1;
                }
                else {
                    thisAns = 1;
                }
                ma[num] = thisAns;
                ans = max(ans, thisAns);
            }
        }
        return ans;
    }
};