/*
 * @Author: LetMeFly
 * @Date: 2026-02-04 21:46:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-04 21:56:05
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int state = 0;
        if (nums[1] <= nums[0]) {
            return false;
        }
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return false;
            }
            if (state == 0) {
                if (nums[i] < nums[i - 1]) {
                    state = 1;
                }
            } else if (state == 1) {
                if (nums[i] > nums[i - 1]) {
                    state = 2;
                }
            } else if (state == 2) {
                if (nums[i] < nums[i - 1]) {
                    return false;
                }
            }
        }
        return state == 2;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[1,3,5,4,2,6]

true
*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        vector<int> t = stringToVector(s);
        cout << sol.isTrionic(t) << endl;
    }
    return 0;
}
#endif