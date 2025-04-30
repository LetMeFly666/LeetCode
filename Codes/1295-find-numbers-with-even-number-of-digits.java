/*
 * @Author: LetMeFly
 * @Date: 2025-04-30 17:24:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-30 17:27:07
 */
class Solution {
    private int getLength(int t) {
        int ans = 0;
        while (t > 0) {
            ans++;
            t /= 10;
        }
        return ans;
    }
    public int findNumbers(int[] nums) {
        int ans = 0;
        for (int t : nums) {
            if (getLength(t) % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
}