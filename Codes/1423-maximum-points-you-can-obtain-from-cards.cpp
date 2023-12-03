/*
 * @Author: LetMeFly
 * @Date: 2023-12-03 14:00:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-03 14:03:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = cardPoints.size() - k;
        int cnt = 0;
        int s = 0;
        for (int i = 0; i < l; i++) {
            cnt += cardPoints[i];
            s += cardPoints[i];
        }
        int m = cnt;
        for (int i = l; i < cardPoints.size(); i++) {
            cnt += cardPoints[i] - cardPoints[i - l];
            m = min(m, cnt);
            s += cardPoints[i];
        }
        return s - m;
    }
};