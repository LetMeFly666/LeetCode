/*
 * @Author: LetMeFly
 * @Date: 2026-08-03 18:28:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-03 18:36:37
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int n;
    vector<int> mem;

    int play(vector<int>& v, int idx=0) {
        if (mem[idx] != INT_MIN) {
            return mem[idx];
        }
        if (idx == n) {
            return mem[idx] = 0;
        }
        int ans = INT_MIN;
        for (int i = 0, cnt = 0; i < 3; i++) {
            if (idx + i >= n) {
                break;
            }
            cnt += v[idx + i];
            ans = max(ans, cnt - play(v, idx + i + 1));
        }
        return mem[idx] = ans;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        mem.resize(n + 1, INT_MIN);
        int score = play(stoneValue);
        return score > 0 ? "Alice" : score ? "Bob" : "Tie";
    }
};
