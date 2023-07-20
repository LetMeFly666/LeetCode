/*
 * @Author: LetMeFly
 * @Date: 2023-07-20 08:14:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-20 08:22:34
 */
#ifdef _WIN32
    #include "_[1,2]toVector.h"
#else
    #define dbg(x) cout << #x << " = " << x << endl
#endif

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int nowM = nums[0], M = nums[0];
        int nowm = nums[0], m = nums[0];
        int s = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nowM = max(nowM + nums[i], nums[i]);
            M = max(M, nowM);
            nowm = min(nowm + nums[i], nums[i]);
            m = min(m, nowm);
            s += nums[i];
        }
        return M < 0 ? M : max(M, s - m);
    }
};