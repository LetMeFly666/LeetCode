/*
 * @Author: LetMeFly
 * @Date: 2022-08-26 10:29:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-26 10:33:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<vector<int>> ans;

    void goon(int k, int n, vector<int> now) {
        if (k == 0 || n == 0) {
            if (k == 0 && n == 0) {
                ans.push_back(now);
            }
            return;
        }
        int nowMax = 0;
        for (int& t : now) {
            nowMax = max(nowMax, t);
        }
        for (int i = nowMax + 1; i < 10; i++) {
            if (n >= i) {
                now.push_back(i);
                goon(k - 1, n - i, now);
                now.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        goon(k, n, {});
        return ans;
    }
};