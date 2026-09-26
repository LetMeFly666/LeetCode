/*
 * @Author: LetMeFly
 * @Date: 2026-05-14 05:27:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-14 05:56:40
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;  // 注意，n是数组长度-1
        int cntN = 0;
        for (int t : nums) {
            t = t < 0 ? -t : t;
            if (t > n || t == 0) {
                return false;
            }
            if (t == n) {
                cntN++;
                continue;
            }
            if (nums[t - 1] < 0) {
                return false;
            }
            nums[t - 1] = -nums[t - 1];
        }
        return cntN == 2;
    }
};

#ifdef _DEBUG
/*
[1,3,3,2]
*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        vector<int> v = stringToVector(s);
        cout << sol.isGood(v) << endl;
    }
    return 0;
}
#endif
