/*
 * @Author: LetMeFly
 * @Date: 2022-09-12 09:23:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-12 09:31:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 枚举答案，O(n^2), O(1)
class Solution {
public:
    int specialArray(vector<int>& nums) {
        for (int ans = 0; ans <= nums.size(); ans++) {
            int cnt = 0;
            for (int& t : nums) {
                cnt += t >= ans;
            }
            if (cnt == ans) {
                return ans;
            }
        }
        return -1;
    }
};
#else  // FirstTry
// SecondTry  // 排序+遍历，O(n log n), O(log n)
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        for (int ans = 1; ans <= nums.size(); ans++) {
            if (nums[ans - 1] >= ans && (ans == nums.size() || nums[ans] < ans)) {
                return ans;
            }
        }
        return -1;
    }
};
#endif  // FirstTry