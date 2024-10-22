/*
 * @Author: LetMeFly
 * @Date: 2024-10-22 18:32:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-22 18:53:49
 */
class Solution {
    public int countCompleteDayPairs(int[] hours) {
        int ans = 0;
        for (int i = 0; i < hours.length; i++) {
            for (int j = i + 1; j < hours.length; j++) {
                ans += (hours[i] + hours[j]) % 24 == 0 ? 1 : 0;
            }
        }
        return ans;
    }
}