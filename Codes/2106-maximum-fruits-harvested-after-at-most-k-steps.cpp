/*
 * @Author: LetMeFly
 * @Date: 2023-05-04 10:10:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-04 10:26:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int minStep(vector<vector<int>>& fruits, int l, int r, int startPos) {
        if (fruits[r][0] <= startPos) {  // 全在起点左边
            return startPos - fruits[l][0];
        }
        else if (fruits[l][0] >= startPos) {  // 全在起点右边
            return fruits[r][0] - startPos;
        }
        else {  // 横跨起点左右
            int leftDistance = startPos - fruits[l][0];
            int rightDistance = fruits[r][0] - startPos;
            return min(2 * leftDistance + rightDistance, leftDistance + 2 * rightDistance);
        }
    }
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = 0;
        int cnt = 0;
        int l = 0;
        for (int r = 0; r < fruits.size(); r++) {
            cnt += fruits[r][1];
            while (l <= r && minStep(fruits, l, r, startPos) > k) {
                cnt -= fruits[l][1];
                l++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};