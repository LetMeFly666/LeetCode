/*
 * @Author: LetMeFly
 * @Date: 2026-10-22 08:03:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-22 18:41:42
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        bool increase = nums[1] == nums[0] + 1;
        for (int i = 1; i < n; i++) {
            if (increase && (nums[i] == nums[i - 1] + 1 || nums[i - 1] == n - 1 && nums[i] == 0)) {
                continue;
            }
            if (!increase && (nums[i] == nums[i - 1] - 1 || nums[i - 1] == 0 && nums[i] == n - 1)) {
                continue;
            }
            return -1;
        }
        if (increase && nums[0] == 0) {
            return 0;
        }
        if (!increase && nums[n - 1] == 0) {
            return 1;
        }
        return 1 + !increase;
    }
};

#ifdef _DEBUG
/*
[0,2,1]

2
*/
/*

*/
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.minOperations(v) << endl;
    }
    return 0;
}
#endif
