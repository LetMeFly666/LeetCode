/*
 * @Author: LetMeFly
 * @Date: 2022-08-05 17:01:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-05 17:08:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FristTry  // 哈希，O(n),O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ma;
        int n = nums.size();
        for (int& t : nums) {
            ma[t]++;
        }
        for (auto& [val, times] : ma) {
            if (times * 2 >= n) {
                return val;
            }
        }
        return -1;  // Fake Return
    }
};
#else  // FristTry
// SecondTry
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 不写了
    }
};
#endif  // FristTry