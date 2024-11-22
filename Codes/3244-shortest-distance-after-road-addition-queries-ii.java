/*
 * @Author: LetMeFly
 * @Date: 2024-11-20 12:58:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-20 13:02:59
 */
class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        int[] transitionTo = new int[n];
        for (int i = 0; i < n; i++) {
            transitionTo[i] = i + 1;
        }
        int[] ans = new int[queries.length];
        int minTimes = n - 1;
        for (int i = 0; i < queries.length; i++) {
            int from = queries[i][0], to =  queries[i][1];
            while (transitionTo[from] < to) {
                minTimes--;
                int originalTo = transitionTo[from];
                transitionTo[from] = to;
                from = originalTo;
            }
            ans[i] = minTimes;
        }
        return ans;
    }
}  // AC,100.00%,79.09%