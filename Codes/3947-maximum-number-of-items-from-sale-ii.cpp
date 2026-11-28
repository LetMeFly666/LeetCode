/*
 * @Author: LetMeFly
 * @Date: 2026-11-28 19:02:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-28 20:32:46
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

    int canGet(int factor, int maxium, const unordered_map<int, int>& factor_num) {
        int ans = 0;
        for (int f = factor; f <= maxium; f += factor) {
            unordered_map<int, int>::const_iterator it = factor_num.find(f);
            if (it != factor_num.end()) {
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
        unordered_map<int, int> factor_num;  // 某个factor的物品有多少个
        for (vector<int>& item : items) {
            factor_num[item[0]]++;
        }

        vector<pair<int, int>> candidates;
        for (vector<int>& item : items) {
            int factor = item[0], price = item[1];
            if (price >= mini2) {
                continue;
            }
            int canGot = canGet(factor, n, factor_num);
            if (canGot) {
                candidates.push_back({price, canGot});
            }
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

#ifdef _DEBUG
/*
[[1,6],[2,4],[3,5]]
19

5
*/
int main() {
    string s;
    int b;
    while (cin >> s >> b) {
        vector<vector<int>> a = stringToVectorVector(s);
        Solution sol;
        cout << sol.maximumSaleItems(a, b) << endl;
    }
    return 0;
}
#endif
