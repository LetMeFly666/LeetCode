/*
 * @Author: LetMeFly
 * @Date: 2022-06-02 11:01:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-02 11:05:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        function<void(int, int)> addOneResult = [&ans](int l, int r) {
            if (l == r)
                ans.push_back(to_string(l));
            else
                ans.push_back(to_string(l) + "->" + to_string(r));
        };
        for (int& t : nums) {
            if (lower < t) {
                addOneResult(lower, t - 1);
            }
            lower = t + 1;
        }
        if (lower <= upper)
            addOneResult(lower, upper);
        return ans; 
    }
};