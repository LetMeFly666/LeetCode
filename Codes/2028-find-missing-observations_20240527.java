/*
 * @Author: LetMeFly
 * @Date: 2024-05-27 21:41:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-27 21:48:49
 */
class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int target = mean * (n + rolls.length);
        for (int i = 0; i < rolls.length; i++) {
            target -= rolls[i];
        }
        if (target < n || target > n * 6) {
            return new int[0];
        }
        int[] ans = new int[n];
        int mean2 = target / n, more = target % n;
        for (int i = 0; i < n; i++) {
            ans[i] = mean2 + (i < more ? 1 : 0);
        }
        return ans;
    }
}