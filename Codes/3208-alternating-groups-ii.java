/*
 * @Author: LetMeFly
 * @Date: 2024-11-28 23:32:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-28 23:38:33
 */
class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int ans = 0;
        int cntDiff = 0;
        for (int i = 1; i < k; i++) {
            if (colors[i] != colors[i - 1]) {
                cntDiff++;
            }
        }
        for (int i = 0; i < colors.length; i++) {
            if (cntDiff == k - 1) {
                ans++;
            }
            if (colors[(i + k) % colors.length] != colors[(i + k - 1) % colors.length]) {
                cntDiff++;
            }
            if (colors[(i + 1) % colors.length] != colors[i]) {
                cntDiff--;
            }
        }
        return ans;
    }
}