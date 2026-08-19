/*
 * @Author: LetMeFly
 * @Date: 2026-08-19 10:52:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-19 10:59:31
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

const int mask1 = 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5;
const int mask2 = 1 << 4 | 1 << 5 | 1 << 6 | 1 << 7;
const int mask3 = 1 << 6 | 1 << 7 | 1 << 8 | 1 << 9;
const int mask4 = mask1 | mask3;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;
        for (vector<int>& people : reservedSeats) {
            reserved[people[0]] |= 1 << people[1];
        }
        int ans = n * 2;
        for (int i = n; i > 0; i--) {
            if (!reserved.count(i) || !(reserved[i] & mask4)) {
                // ans -= 0;
            } else if (reserved[i] & mask1 || reserved[i] & mask2 || reserved[i] & mask3) {
                ans--;
            } else {
                ans -= 2;
            }
        }
        return ans;
    }
};
