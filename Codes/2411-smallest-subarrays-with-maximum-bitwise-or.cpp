/*
 * @Author: LetMeFly
 * @Date: 2025-07-29 23:42:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-30 00:00:01
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> lastPos(31);
        for (int i = nums.size() - 1; i >= 0; i--) {
            int last = i;
            for (int j = 0; j < 31; j++) {
                if (nums[i] >> j & 1) {
                    lastPos[j] = i;
                } else {
                    last = max(last, lastPos[j]);
                }
            }
            ans[i] = max(ans[i], last - i + 1);
        }
        return ans;
    }
};


#if defined(_WIN32) || defined(__APPLE__)
/*
 [1,0,2,1,3]
*/
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        debug(sol.smallestSubarrays(v));
    }
    return 0;
}
#endif