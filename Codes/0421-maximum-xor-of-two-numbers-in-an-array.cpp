/*
 * @Author: LetMeFly
 * @Date: 2022-10-19 16:40:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-19 17:56:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Half
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        vector<int> first(nums), second(nums);
        for (int i = 30; i >= 0; i--) {
            vector<int> first0, first1, second0, second1;
            for (int& t: first) {
                if (t >> i)
                    first1.push_back(t);
                else
                    first0
            }

        }
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            unordered_set<int> se;
            for (int& t : nums) {
                se.insert(t >> i);
            }
            int wantBe = (ans << 1) + 1;
            bool found = false;
            for (int& t : nums) {
                if (se.count(wantBe ^ (t >> i))) {
                    found = true;
                    break;
                }
            }
            ans = found ? wantBe : wantBe - 1;
        }
        return ans;
    }
};
#endif  // FirstTry