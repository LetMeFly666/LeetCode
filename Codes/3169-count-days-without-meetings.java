/*
 * @Author: LetMeFly
 * @Date: 2025-07-11 23:25:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-12 16:53:21
 */
import java.util.Arrays;

class Solution {
    public int countDays(int days, int[][] meetings) {
        int ans = 0;
        int last = 0;
        Arrays.sort(meetings);
        for (int[] me : meetings) {
            if (me[0] > last + 1) {
                ans += me[0] - last - 1;
            }
            last = Math.max(last, me[1]);
        }
        ans += days - last;
        return ans;
    }
}