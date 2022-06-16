/*
 * @Author: LetMeFly
 * @Date: 2022-06-16 10:24:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-16 10:35:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error，是pair(num[i], num[j])的个数，不是pair(i, j)的个数
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> ma;
        for (int& t : nums) {
            ma[t]++;
        }
        if (!k) {
            for (auto[a, b] : ma) {
                ans += b * (b - 1) / 2;
            }
            return ans;
        }
        for (auto [a, b] : ma) {
            if (ma.count(a + k)) {
                ans += b * ma[a + k];
            }
        }
        return ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // j必须> i
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        unordered_set<int> se;
        for (int& t : nums) {
            se.insert(t);
        }
        for (int t : se) {
            if (se.count(t + k)) {
                ans++;
            }
        }
        return ans;
    }
};
#else  // SecondTry
// ThirdTry
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (!k) {  // k = 0 的时候，必须出现过不只一次这个数，才能找到满足j > i且nums[j] = nums[i]的pair
            int ans = 0;
            unordered_map<int, int> ma;
            for (int& t : nums) {
                ma[t]++;
            }
            for (auto[a, b] : ma) {
                if (b > 1) {
                    ans++;
                }
            }
            return ans;
        }
        int ans = 0;
        unordered_set<int> se;
        for (int& t : nums) {
            se.insert(t);
        }
        for (int t : se) {
            if (se.count(t + k)) {
                ans++;
            }
        }
        return ans;
    }
};
#endif  // SecondTry
#endif  // FirstTry