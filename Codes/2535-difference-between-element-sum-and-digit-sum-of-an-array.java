/*
 * @Author: LetMeFly
 * @Date: 2024-09-26 18:07:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-26 18:10:12
 */
class Solution {
    private int getSum(int t) {
        int ans = 0;
        while (t > 0) {
            ans += t % 10;
            t /= 10;
        }
        return ans;
    }

    public int differenceOfSum(int[] nums) {
        int x = 0, y = 0;
        for (int t : nums) {
            x += t;
            y += getSum(t);
        }
        return Math.abs(x - y);
    }
}