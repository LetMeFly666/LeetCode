/*
 * @Author: LetMeFly
 * @Date: 2026-08-19 10:52:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-19 11:43:10
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
        int ans = (n - reserved.size()) * 2;
        for (auto [_, line] : reserved) {
            if (!(line & mask4)) {
                ans += 2;
            } else if (!(line & mask1) || !(line & mask2) || !(line & mask3)) {
                ans += 1;
            }
        }
        return ans;
    }
};

#ifdef _DEBUG
/*
2
[[2,1],[1,8],[2,6]]

2
*/
int main() {
    int n;
    string s;
    while (cin >> n >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        cout << sol.maxNumberOfFamilies(n, v) << endl;
    }
    return 0;
}
#endif
