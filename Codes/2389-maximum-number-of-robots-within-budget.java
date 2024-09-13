/*
 * @Author: LetMeFly
 * @Date: 2024-09-13 13:09:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-13 18:06:26
 */

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int maximumRobots(int[] chargeTimes, int[] runningCosts, long budget) {
        int ans = 0;
        long sumCosts = 0;
        Deque<Integer> q = new ArrayDeque<>();
        for (int l = 0, r = 0; r < chargeTimes.length; r++) {
            while (!q.isEmpty() && chargeTimes[r] >= chargeTimes[q.getLast()]) {
                q.pollLast();
            }
            q.addLast(r);
            sumCosts += runningCosts[r];

            while (!q.isEmpty() && chargeTimes[q.getFirst()] + (long)(r - l + 1) * sumCosts > budget) {
                if (l == q.getFirst()) {
                    q.pop();
                }
                sumCosts -= runningCosts[l++];
            }

            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
}