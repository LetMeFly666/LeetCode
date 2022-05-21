// /*
//  * @Author: LetMeFly
//  * @Date: 2021-09-30 18:03:41
//  * @LastEditors: LetMeFly
//  * @LastEditTime: 2021-09-30 18:11:00
//  */
// #include <bits/stdc++.h>
// using namespace std;
// #define mem(a) memset(a, 0, sizeof(a))
// #define dbg(x) cout << #x << " = " << x << endl
// #define fi(i, l, r) for (int i = l; i < r; i++)
// #define cd(a) scanf("%d", &a)
// typedef long long ll;
// class Solution {
// public:
//     int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
//         int ans = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
//         int cx = ax2, cy = ay1;
//         int dx = bx1, dy = by2;
//         if (dy < cy || dx > cx) ;
//         // else if (dy <= ay2) {
//         //     if (dx >= ax1) {
//         //         ans -= (cx - dx) * (dy - cy);
//         //     }
//         //     else { // dx < ax1
//         //         ans -= (ax2 - ax1) * (dy - cy);
//         //     }
//         // }
//         // else { // dy > ay2
//         //     if 
//         // }
//         return ans;
//     }
// };

// FWb
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2 - ay1), area2 = (bx2 - bx1) * (by2 - by1);
        int overlapWidth = min(ax2, bx2) - max(ax1, bx1), overlapHeight = min(ay2, by2) - max(ay1, by1);
        int overlapArea = max(overlapWidth, 0) * max(overlapHeight, 0);
        return area1 + area2 - overlapArea;
    }
};