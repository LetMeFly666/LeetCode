/*
 * @Author: LetMeFly
 * @Date: 2022-11-22 11:08:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-22 11:28:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#define FirstTry

#ifdef FirstTry  // 前缀和 + 哈希表
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        unordered_set<int> se;
        for (int i = 2; i <= n; i++) {
            se.insert(prefix[i - 2] % k);
            if (se.count(prefix[i] % k))
                return true;
        }
        return false;
    }
};
#else  // FirstTry
// SecondTry  // 使用布尔数组小优化
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // 啊哈，忽然发现$k$是INT范围，此方法无效
    }
};
#endif  // FirstTry