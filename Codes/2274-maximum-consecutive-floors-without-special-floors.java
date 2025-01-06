/*
 * @Author: LetMeFly
 * @Date: 2025-01-06 20:39:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-06 20:40:24
 */
import java.util.Arrays;

class Solution {
    public int maxConsecutive(int bottom, int top, int[] special) {
        Arrays.sort(special);
        int ans = Math.max(special[0] - bottom, top - special[special.length - 1]);
        for (int i = 1; i < special.length; i++) {
            ans = Math.max(ans, special[i] - special[i - 1] - 1);
        }
        return ans;
    }
}