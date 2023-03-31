/*
 * @Author: LetMeFly
 * @Date: 2023-03-31 09:00:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-31 09:16:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 哈希表
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> se;
        for (int t : nums) {
            se.insert(t);
        }
        int ans = 0;
        for (int t : nums) {
            ans += se.count(t + diff) && se.count(t + 2 * diff);
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // 三指针
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        for (int i = 0, j = 0, k = 0; k < nums.size(); k++) {
            while (nums[j] + diff < nums[k]) {
                j++;
            }
            if (nums[j] + diff > nums[k]) {
                continue;
            }
            while (nums[i] + diff < nums[j]) {
                i++;
            }
            if (nums[i] + diff == nums[j]) {
                ans++;
            }
        }
        return ans;
    }
};
#endif  // FirstTry