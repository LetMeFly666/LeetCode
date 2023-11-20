/*
 * @Author: LetMeFly
 * @Date: 2023-11-20 10:56:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-20 11:07:15
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

struct Status {
    int lSum, rSum, MSum, iSum;
};

class Solution {
private:
    Status get(vector<int>& a, int l, int r) {  // get[l, r]
        if (l == r) {
            return {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lStatus = get(a, l, m);
        Status rStatus = get(a, m + 1, r);
        return {
            max(lStatus.lSum, lStatus.iSum + rStatus.lSum),
            max(rStatus.rSum, lStatus.rSum + rStatus.iSum),
            max(lStatus.MSum, max(rStatus.MSum, lStatus.rSum + rStatus.lSum)),
            lStatus.iSum + rStatus.iSum
        };
    }
public:
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).MSum;
    }
};