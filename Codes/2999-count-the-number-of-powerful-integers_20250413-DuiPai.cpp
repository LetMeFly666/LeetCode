/*
 * @Author: LetMeFly
 * @Date: 2025-04-13 11:41:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-13 11:46:18
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
        if (i == start.size()) {
            return 1;
        }

        if (!limitLow && !limitHigh && cache.count(i)) {
            return cache[i]; // 之前计算过
        }

        // 第 i 个数位可以从 lo 枚举到 hi
        // 如果对数位还有其它约束，应当只在下面的 for 循环做限制，不应修改 lo 或 hi
        int lo = limitLow ? start[i] - '0' : 0;
        int hi = limitHigh ? finish[i] - '0' : 9;

        long long res = 0;
        if (i < nonFixed) { // 枚举这个数位填什么
            for (int d = lo; d <= min(hi, limit); d++) {
                res += dfs(i + 1, limitLow && d == lo, limitHigh && d == hi);
            }
        } else { // 这个数位只能填 s[i-diff]
            int x = s[i - nonFixed] - '0';
            if (lo <= x && x <= hi) { // 题目保证 x <= limit，无需判断
                res = dfs(i + 1, limitLow && x == lo, limitHigh && x == hi);
            }
        }

        if (!limitLow && !limitHigh) {
            memo[i] = res; // 记忆化 (i,false,false)
        }
        return res;
    };
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        this->start = to_string(start);
        this->finish = to_string(finish);
        n = this->finish.size();
        this->start = string(n - this->start.size(), '0') + this->start; // 补前导零，和 high 对齐
        nonFixed = n - s.size();
        suffix = s;
        
        return dfs(0, true, true);
    }
};

// copy and change from https://leetcode.cn/problems/count-the-number-of-powerful-integers/solutions/2595149/shu-wei-dp-shang-xia-jie-mo-ban-fu-ti-da-h6ci/