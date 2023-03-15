/*
 * @Author: LetMeFly
 * @Date: 2023-03-15 10:14:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-15 10:29:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error，不能使用滑动窗口，因为nums不是非负的
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0;
        int cnt = 0;
        for (int r = 0; r < nums.size(); r++) {
            cnt += nums[r];
            
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> ma;
        ma[0] = 1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += nums[i];
            if (ma.count(cnt - k)) {
                ans += ma[cnt - k];
            }
            ma[cnt]++;
        }
        return ans;
    }
};
#endif  // FirstTry