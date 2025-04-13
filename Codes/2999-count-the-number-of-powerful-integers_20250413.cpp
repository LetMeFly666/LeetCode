/*
 * @Author: LetMeFly
 * @Date: 2025-04-13 11:03:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-13 11:26:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
private:
    int limit, n, nonFixed;
    string suffix, start, finish;
    unordered_map<int, int> cache;

    ll dfs(int i, bool limitLow, bool limitHigh) {
        if (i == n) {
            return 1;
        }
        if (!limitLow && !limitHigh && cache.count(i)) {
            return cache[i];
        }
        int low = limitLow ? start[i] - '0' : 0;
        int high = limitHigh ? finish[i] - '0' : 9;
        ll ans = 0;
        if (i < nonFixed) {
            for (int d = low; d <= min(high, limit); d++) {
                ans += dfs(i + 1, limitLow && d == low, limitHigh && d == high);
            }
        } else {
            int x = suffix[i - nonFixed] - '0';
            if (low <= x && x <= high) {  // 题目限制一定小于limit
                ans = dfs(i + 1, limitLow && x == low, limitHigh && x == high);
            }
        }
        return cache[i] = ans;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        this->limit = limit;
        suffix = move(s);
        this->finish = to_string(finish);
        n = this->finish.size();
        this->start = to_string(start);
        this->start = string(n - this->start.size(), '0') + this->start;
        nonFixed = n - this->suffix.size();

        return dfs(0, true, true);
    }
};