/*
 * @Author: LetMeFly
 * @Date: 2025-12-24 13:30:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-24 18:35:17
 */
import java.util.Arrays;

class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int cnt = 0;
        for (int t : apple) {
            cnt += t;
        }
        Arrays.sort(capacity);
        int ans = 0;
        for (int i = capacity.length - 1; i >= 0; i--) {
            cnt -= capacity[i];
            ans++;
            if (cnt <= 0) {
                return ans;
            }
        }
        return -1;  // FAKE RETURN
    }
}