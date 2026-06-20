/*
 * @Author: LetMeFly
 * @Date: 2026-06-20 10:09:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-20 10:12:06
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int cal(vector<vector<int>>& restrictions, int a, int b) {
        
    }
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({0, 0});
        sort(restrictions.begin(), restrictions.end());
        int ans = 0;
        for (int i = 1; i < restrictions.size(); i++) {
            ans = max(ans, cal(restrictions, i - 1, i));
        }
        return ans;
    }
};
