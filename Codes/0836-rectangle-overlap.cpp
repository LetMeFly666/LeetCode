/*
 * @Author: LetMeFly
 * @Date: 2026-09-14 10:49:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-14 10:50:53
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool ok(int la, int ra, int lb, int rb) {
        if (la > lb) {
            swap(la, lb);
            swap(ra, rb);
        }
        return lb < ra;
    }
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return ok(rec1[0], rec1[1], rec2[0], rec2[1]) && ok(rec1[2], rec1[3], rec2[2], rec2[3]);
    }
};
