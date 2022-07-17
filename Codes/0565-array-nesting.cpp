/*
 * @Author: LetMeFly
 * @Date: 2022-07-17 09:31:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-17 09:37:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 图
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            while (!visited[i]) {
                visited[i] = true;
                cnt++;
                i = nums[i];
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // 原地标记
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            while (nums[i] != n) {
                int next = nums[i];
                nums[i] = n;
                cnt++;
                i = next;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
#endif  // FirstTry