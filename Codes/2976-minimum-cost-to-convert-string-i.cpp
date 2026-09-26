/*
 * @Author: LetMeFly
 * @Date: 2026-01-31 12:12:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-31 12:22:44
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ll floyd[26][26];
        memset(floyd, 0x3f, sizeof(floyd));
        for (int i = 0; i < 26; i++) {
            floyd[i][i] = 0;
        }
        for (int i = 0; i < original.size(); i++) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            floyd[x][y] = min(floyd[x][y], (ll)cost[i]);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
                }
            }
        }
        
        ll ans = 0;
        for (int i = 0; i < source.size(); i++) {
            ll cost = floyd[source[i] - 'a'][target[i] - 'a'];
            if (cost > 1000000000000) {
                return -1;
            }
            ans += cost;
        }
        return ans;
    }
};