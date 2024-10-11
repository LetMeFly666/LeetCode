/*
 * @Author: LetMeFly
 * @Date: 2024-10-11 22:56:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-11 22:56:56
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    public long numberOfPairs(int[] nums1, int[] nums2, int k) {
        Map<Integer, Integer> ma = new HashMap<>();
        for (int t : nums1) {
            if (t % k != 0) {
                continue;
            }
            t /= k;
            int sqrt_ = (int)Math.sqrt(t);
            for (int i = 1; i <= sqrt_; i++) {
                if (t % i == 0) {
                    ma.merge(i, 1, Integer::sum);
                    ma.merge(t / i, 1, Integer::sum);
                }
            }
            if (sqrt_ * sqrt_ == t) {
                ma.merge(sqrt_, -1, Integer::sum);
            }
        }
        long ans = 0;
        for (int t : nums2) {
            ans += (long)ma.getOrDefault(t, 0);
        }
        return ans;
    }
}