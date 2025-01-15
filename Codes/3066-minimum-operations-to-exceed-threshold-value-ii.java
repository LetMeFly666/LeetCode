/*
 * @Author: LetMeFly
 * @Date: 2025-01-15 14:22:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-15 14:30:40
 */
import java.util.PriorityQueue;

class Solution {
    public int minOperations(int[] nums, int k) {
        int ans = 0;
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (int t : nums) {
            pq.add((long)t);
        }
        while (pq.peek() < k) {
            long x = pq.remove(), y = pq.remove();
            pq.add(Math.min(x, y) * 2 + Math.max(x, y));
            ans++;
        }
        return ans;
    }
}