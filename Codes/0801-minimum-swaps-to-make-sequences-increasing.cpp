/*
 * @Author: LetMeFly
 * @Date: 2022-10-10 19:34:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-10 19:46:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int swap = 1, noSwap = 0;
        int n = nums1.size();
        int newSwap, newNoSwap;
        for (int i = 1; i < n; i++) {
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                newSwap = swap + 1, newNoSwap = noSwap;
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                newSwap = min(swap, noSwap + 1);
                newNoSwap = min(swap, noSwap);
            }
            swap = newSwap, noSwap = newNoSwap;
        }
        return min(swap, noSwap);
    }
};
#else  // FirstTry
#ifdef SecondTry  // Java
class Solution {
    public int minSwap(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[][] f = new int[2][2];
        f[0][1] = 1;
        for (int i = 1; i < n; i++) {
            int a = n + 10, b = n + 10;
            int prev = (i - 1) & 1, cur = i & 1; // 避免重复的 & 操作
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                a = f[prev][0];
                b = f[prev][1] + 1;
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                a = Math.min(a, f[prev][1]);
                b = Math.min(b, f[prev][0] + 1);
            }
            f[cur][0] = a; f[cur][1] = b;
        }
        return Math.min(f[(n - 1) & 1][0], f[(n - 1) & 1][1]);
    }
}
#else  // SecondTry
// ThirdTry
#endif  // SecondTry
#endif  // FirstTry