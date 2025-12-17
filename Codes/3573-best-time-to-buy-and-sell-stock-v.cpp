/*
 * @Author: LetMeFly
 * @Date: 2025-12-17 21:38:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-17 23:02:36
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
private:
    vector<int> prices;
    unordered_map<int, int> cache;

    inline int getKey(int i, int j, int status) {
        return i * 3000 + j * 1000 + status;
    }

    ll dfs(int i, int j, int status) {
        // 0~i天 最多交易j次
        // status: 0无1买2空头
        
        int key = getKey(i, j, status);
        if (cache.count(key)) {
            return cache[key];
        }

        if (j < 0) {
            return -1'000'000'000'000'000;
        }
        if (i < 0) {
            return status ? -1'000'000'000'000'000 : 0;
        }

        if (status == 0) {
            return cache[key] = max({dfs(i - 1, j, 0), dfs(i - 1, j - 1, 1) + prices[i], dfs(i - 1, j - 1, 2) - prices[i]});
        } else if (status == 1) {
            return cache[key] = max(dfs(i - 1, j - 1, 0) - prices[i], dfs(i - 1, j, 0));
        } else {
            return cache[key] = max(dfs(i - 1, j - 1, 0) + prices[i], dfs(i - 1, j, 2));
        }
    }
public:
    ll maximumProfit(vector<int>& prices, int k) {
        this->prices = move(prices);
        return dfs(this->prices.size() - 1, k, 0);
    }
};