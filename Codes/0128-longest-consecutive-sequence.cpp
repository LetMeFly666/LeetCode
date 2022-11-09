/*
 * @Author: LetMeFly
 * @Date: 2022-07-21 22:14:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-21 22:38:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 方法一：排序，非O(n)时间复杂度
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int lastNum = -INT_MAX;
        int nowCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == lastNum)
                continue;
            if (nums[i] == lastNum + 1) {
                nowCnt++;
            }
            else {
                nowCnt = 1;
            }
            lastNum = nums[i];
            ans = max(ans, nowCnt);
        }
        return ans;
    }
};
#else  // FirstTry
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> se;
        int ans = 0;
        for (int& t : nums) {
            se.insert(t);
        }
        for (int t : se) {
            if (!se.count(t - 1)) {  // 一串数字的最小的
                int thisCnt = 0;
                while (se.count(t)) {
                    thisCnt++;
                    t++;
                }
                ans = max(ans, thisCnt);
            }
        }
        return ans;
    }
};
#endif  // FirstTry