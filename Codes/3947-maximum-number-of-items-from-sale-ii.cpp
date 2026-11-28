/*
 * @Author: LetMeFly
 * @Date: 2026-11-28 19:02:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-28 19:54:36
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int getMiniPrice(vector<vector<int>>& items) {
        int ans = items[0][1];
        for (vector<int>& item : items) {
            ans = min(ans, item[1]);
        }
        return ans;
    }

    int canGet(int factor, int maxium, const unordered_map<int, int>& price_num) {
        int ans = 0;
        for (int f = factor; f <= maxium; f += factor) {
            unordered_map<int, int>::const_iterator it = price_num.find(f);
            if (it != price_num.end()) {
                ans += it->second;
            }
        }
        return --ans;
    }
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int mini_price = getMiniPrice(items);
        int mini2 = mini_price * 2;
        int n = items.size();
        unordered_map<int, int> price_num;  // 某个价格的物品有多少个
        for (vector<int>& item : items) {
            price_num[item[1]]++;
        }

        vector<pair<int, int>> candidates;
        for (vector<int>& item : items) {
            int factor = item[0], price = item[1];
            if (price >= mini2) {
                continue;
            }
            candidates.push_back({price, canGet(factor, n, price_num)});
        }
        ranges::sort(candidates);
        
        int ans = 0;
        for (auto [price, num] : candidates) {
            int quantity = min(budget / price, num);
            if (!quantity) {
                break;
            }
            ans += num * 2;
            budget -= price * quantity;
        }
        return ans + budget / mini_price;
    }
};
