/*
 * @Author: LetMeFly
 * @Date: 2022-07-26 11:22:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-26 11:27:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // unordered_map, O(n),O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> ma;
        for (int& t : nums) {
            ma[t]++;
        }
        for (auto& [num, times] : ma) {
            if (times == 1)
                return num;
        }
        return -1;  // FAKE_RETURN
    }
};
#else  // FirstTry
// SecondTry  // 二进制位运算，O(n log C),O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int times = 0;
            for (int& t : nums) {
                times += (t >> i) & 1;
            }
            if (times % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
#endif  // FirstTry