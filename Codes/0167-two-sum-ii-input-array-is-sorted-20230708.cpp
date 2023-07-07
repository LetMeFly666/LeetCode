/*
 * @Author: LetMeFly
 * @Date: 2023-07-08 07:25:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-08 07:36:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 方法一，二分，O(n log n) + O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            int finding = target - numbers[i];
            vector<int>::iterator it = lower_bound(numbers.begin() + i + 1, numbers.end(), finding);
            if (it != numbers.end() && *it == finding) {
                return {i + 1, int(it - numbers.begin() + 1)};
            }
        }
        return {};  // Fake Return
    }
};
#else  // FirstTry
// SecondTry  // 方法二，双指针，O(n) + O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int l = 0, r = numbers.size() - 1; l < r;) {
            int s = numbers[l] + numbers[r];
            if (s == target) {
                return {l + 1, r + 1};
            }
            else if (s < target) {
                l++;
            }
            else {
                r--;
            }
        }
        return {};  // Fake Return
    }
};
#endif  // FirstTry