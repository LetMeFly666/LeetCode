/*
 * @Author: LetMeFly
 * @Date: 2025-05-23 23:35:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-23 23:57:57
 */
import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    public int maxRemoval(int[] nums, int[][] queries) {
        Arrays.sort(queries, (a, b) -> a[0] - b[0]);
        int[] diff = new int[nums.length + 1];
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int in = 0, iq = 0, cnt = 0; in < nums.length; in++) {
            cnt += diff[in];
            while (iq < queries.length && queries[iq][0] <= in) {
                pq.add(queries[iq++][1]);
            }
            while (cnt < nums[in] && !pq.isEmpty() && pq.peek() >= in) {
                cnt++;
                diff[pq.poll() + 1]--;
            }
            if (cnt < nums[in]) {
                return -1;
            }
        }
        return pq.size();
    }
}