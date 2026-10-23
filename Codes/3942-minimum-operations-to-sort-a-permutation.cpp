/*
 * @Author: LetMeFly
 * @Date: 2026-10-22 08:03:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-23 12:50:28
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

#ifndef THIS_IS_JUST_NOT_DEFINED
// 这里是正确解法
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        int start = ranges::find(nums, 0) - nums.begin();
        int diff = nums[(start + 1) % n] == 1 ? 1 : -1;
        for (int i = 1; i < n; i++) {
            if (nums[(start + i) % n] != (nums[(start + i - 1) % n] + diff + n) % n) {
                return -1;
            }
        }
        
        if (diff == 1) {
            return min(start, n - start + 2);  // 左移：start次 | 右移：n-start次+数组翻转2次
        } else {
            /*
                2 1 0 3
                n=4 start=2
                右移：n - start
                3 0 1 2
                0 1 2 3
                
                左移：start + 2
                1 0 3 2
                0 3 2 1
                3 2 1 0
                0 1 2 3
            */
            return min(start  +2, n - start);
        }
    }
};
#else  // 以下是archive的错误解法
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
#endif

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
