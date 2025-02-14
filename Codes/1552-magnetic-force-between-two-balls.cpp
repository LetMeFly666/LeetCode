/*
 * @Author: LetMeFly
 * @Date: 2025-02-14 10:45:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-14 10:55:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool check(vector<int>& v, int m, int d) {
        int lastPosition = -1000000000;
        for (int t : v) {
            if (t - lastPosition >= d) {
                m--;
                if (!m) {
                    return true;
                }
                lastPosition = t;
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1, r = position.back() - position[0];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(position, m, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};