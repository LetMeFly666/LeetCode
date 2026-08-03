/*
 * @Author: LetMeFly
 * @Date: 2026-08-03 18:28:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-03 18:33:32
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int n;

    int play(vector<int>& v, int idx=0) {
        if (idx == n) {
            return 0;
        }
        int ans = INT_MIN;
        for (int i = 0, cnt = 0; i < 3; i++) {
            if (idx + i >= n) {
                break;
            }
            cnt += v[idx + i];
            ans = max(ans, cnt + play(v, idx + i + 1));
        }
        return ans;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        int score = play(stoneValue);
        return score > 0 ? "Alice" : score ? "Bob" : "Tie";
    }
};
