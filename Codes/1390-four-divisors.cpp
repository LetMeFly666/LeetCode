#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static unordered_map<int, pair<int, int>> cache;

    pair<int, int> genWithTime(int n) {
        if (cache.count(n)) {
            return cache[n];
        }
        int k = sqrt(n);
        for (int i = 2; i <= k; i++) {
            if (n % i == 0) {
                auto[remainNum, remainSum] = genWithTime(n / i);
                return cache[n] = {remainNum + 1, remainSum + i};
            }
        }
        return cache[n] = {1, n};
    }

    int gen(int n) {
        if (cache.count(n)) {
            auto[num, sum] = cache[n];
            return num == 4 ? sum : 0;
        }
        int k = sqrt(n);
        for (int i = 2; i <= k; i++) {
            if (n % i == 0) {
                auto[remainNum, remainSum] = genWithTime(n / i);
                if (remainNum == 3) {
                    cache[n] = {4, i + remainSum};
                    return i + remainSum;
                }
                break;
            }
        }
        cache[n] = {4, 0};
        return 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int t : nums) {
            ans += gen(t);
        }
        return ans;
    }
};

unordered_map<int, pair<int, int>> Solution::cache;