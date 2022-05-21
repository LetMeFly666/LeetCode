/*
 * @Author: LetMeFly
 * @Date: 2022-04-06 22:32:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-15 10:08:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTime
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char> se;
        int r = -1;
        for (int l = 0; l < s.size(); l++) {
            if (l) {  // 如果l≠0，左指针右移一格
                se.erase(s[l - 1]);
            }
            while (r + 1 < s.size() && !se.count(s[r + 1])) {
                se.insert(s[++r]);
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
#else

#ifdef SecondTimeSameDay
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char> se;
        int r = -1;
        for (int l = 0; l < s.size(); l++) {
            if (l) {
                se.erase(s[l - 1]);
            }
            while (r + 1 < s.size() && !se.count(s[r + 1])) {
                se.insert(s[++r]);
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
#else

#ifdef After2Days
// 2天后再打 ，to 2022-04-08 22:59:50
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char> se;
        int r = -1;
        for (int l = 0; l < s.size(); l++) {
            if (l)
                se.erase(s[l - 1]);
            while (r + 1 < s.size() && !se.count(s[r + 1])) {
                se.insert(s[++r]);
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

#else
#ifdef After1Week
// 一周后再打，to 2022-04-15 09:58:48
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char> se;
        int r = -1;
        for (int l = 0; l < s.size(); l++) {
            if (l) {
                se.erase(s[l - 1]);
            }
            // se.insert(s[l]);  // 这一行不能写！！！
            while (r + 1 < s.size() && !se.count(s[r + 1])) {
                se.insert(s[++r]);
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
#else
/** 当天用数组代替unordered_set，速度快了内存小了
 * 执行用时：4 ms, 在所有 C++ 提交中击败了97.33%的用户 
 * 内存消耗：6.7 MB, 在所有 C++ 提交中击败了94.63%的用户
 * 通过测试用例：987 / 987
 * 完成时间：2022-04-15 10:05:41
*/ 
using uc = unsigned char;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        bool cnt[256] = {0};
        int r = -1;
        for (int l = 0; l < s.size(); l++) {
            if (l)
                cnt[(uc)s[l - 1]] = false;
            while (r + 1 < s.size() && !cnt[(uc)s[r + 1]]) {
                cnt[(uc)s[++r]] = true;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

#endif
#endif
#endif
#endif