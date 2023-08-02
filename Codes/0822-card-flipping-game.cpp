/*
 * @Author: LetMeFly
 * @Date: 2023-08-02 07:44:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-02 07:56:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FristTry  // Error，自己的背面和任意的正面不同（和自己的正面也不能相同）
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_map<int, int> ma;
        int n = fronts.size();
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) {
                ma[fronts[i]]++;
            }
        }
        int ans = 2100;
        for (int i = 0; i < n; i++) {
            int lessThan = (fronts[i] == backs[i]);
            if (ma[fronts[i]] <= lessThan) {
                ans = min(ans, fronts[i]);
            }
            if (ma[backs[i]] <= lessThan) {
                ans = min(ans, backs[i]);
            }            
        }
        return ans == 2100 ? 0 : ans;
    }
};
#else  // FristTry
// SecondTry
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> se;
        int n = fronts.size();
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) {
                se.insert(fronts[i]);
            }
        }
        int ans = 2001;
        for (int i = 0; i < n; i++) {
            if (!se.count(fronts[i])) {
                ans = min(ans, fronts[i]);
            }
            if (!se.count(backs[i])) {
                ans = min(ans, backs[i]);
            }
        }
        return ans == 2001 ? 0 : ans;
    }
};
#endif  // FristTry