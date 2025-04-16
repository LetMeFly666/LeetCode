/*
 * @Author: LetMeFly
 * @Date: 2025-04-16 20:27:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-16 20:49:27
 */
import java.util.Map;
import java.util.HashMap;

// // CE
// class Solution {
//     public long countGood(int[] nums, int k) {
//         long ans = 0, now = 0;
//         Map<Integer, Integer> ma = new HashMap<>();
//         for (int l = 0, r = 0; r < nums.length; r++) {
//             now += ma[nums[r]]++;
//             while (now >= k) {
//                 now -= --ma[nums[l++]];
//             }
//             ans += now;
//         }
//         return ans;
//     }
// }

class Solution {
    public long countGood(int[] nums, int k) {
        long ans = 0, now = 0;
        Map<Integer, Integer> ma = new HashMap<>();
        for (int l = 0, r = 0; r < nums.length; r++) {
            now += ma.merge(nums[r], 1, Integer::sum) - 1;
            while (now >= k) {
                now -= ma.merge(nums[l++], -1, Integer::sum);
            }
            ans += l;
        }
        return ans;
    }
}