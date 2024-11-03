/*
 * @Author: LetMeFly
 * @Date: 2024-11-03 14:39:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-03 14:51:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

struct my_hash {
    size_t operator()(const vector<int>& v) const {
        size_t ans = 0;
        for (int t : v) {
            ans = ans * 15 + t;
        }
        return ans;
    }
};

class Solution {
private:
    unordered_map<vector<int>, int, my_hash> cache;

    inline bool canThisSpecial(vector<int>& thisSpecial, vector<int>& needs) {
        for (int i = 0; i < needs.size(); i++) {
            if (thisSpecial[i] > needs[i]) {
                return false;
            }
        }
        return true;
    }

    inline void useThisSpecial(vector<int>& thisSpecial, vector<int>& needs) {
        for (int i = 0; i < needs.size(); i++) {
            needs[i] -= thisSpecial[i];
        }
    }

    inline void cancelThisSpecial(vector<int>& thisSpecial, vector<int>& needs) {
        for (int i = 0; i < needs.size(); i++) {
            needs[i] += thisSpecial[i];
        }
    }

    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if (cache.count(needs)) {
            return cache[needs];
        }
        int ans = 0;
        for (int i = 0; i < needs.size(); i++) {
            ans += needs[i] * price[i];
        }
        for (vector<int>& thisSpecial : special) {
            if (canThisSpecial(thisSpecial, needs)) {
                useThisSpecial(thisSpecial, needs);
                ans = min(ans, thisSpecial.back() + dfs(price, special, needs));
                cancelThisSpecial(thisSpecial, needs);
            }
        }
        return cache[needs] = ans;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }
};