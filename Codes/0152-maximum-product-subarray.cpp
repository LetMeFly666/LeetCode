/*
 * @Author: LetMeFly
 * @Date: 2022-08-01 08:48:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-01 09:02:52
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int m = nums[0], M = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int lastm = m, lastM = M;
            m = min(nums[i], min(lastm * nums[i], lastM * nums[i]));
            M = max(nums[i], max(lastm * nums[i], lastM * nums[i]));
            ans = max(ans, M);
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // 对FirstTry略有改动，略微减小了计算量，相当于乘法计算只分别计算了一次
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int m = nums[0], M = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int timesLastm = m * nums[i];
            int timesLastM = M * nums[i];
            m = min(nums[i], min(timesLastm, timesLastM));
            M = max(nums[i], max(timesLastm, timesLastM));
            ans = max(ans, M);
        }
        return ans;
    }
};
#endif  // FirstTry