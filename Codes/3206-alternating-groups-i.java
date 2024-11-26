/*
 * @Author: LetMeFly
 * @Date: 2024-11-26 23:22:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-26 23:24:05
 */
class Solution {
    public int numberOfAlternatingGroups(int[] colors) {
        int ans = 0;
        for (int i = 0; i < colors.length; i++) {
            if (colors[i] != colors[(i + 1) % colors.length] && colors[i] == colors[(i + 2) % colors.length]) {
                ans++;
            }
        }
        return ans;
    }
}