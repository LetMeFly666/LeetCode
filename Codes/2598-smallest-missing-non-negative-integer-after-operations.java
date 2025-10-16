/*
 * @Author: LetMeFly
 * @Date: 2025-10-16 19:40:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-16 19:59:10
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int t : nums) {
            cnt.merge((t % value + value) % value, 1, Integer::sum);
        }
        int ans = 0;
        while (cnt.merge(ans % value, -1, Integer::sum) >= 0) {  // 记得是大于等于
            ans++;
        }
        return ans;
    }
}