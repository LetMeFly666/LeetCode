/*
 * @Author: LetMeFly
 * @Date: 2024-11-19 14:46:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-19 14:58:40
 */
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        int[] shortest = new int[n];
        List<Integer>[] fromList = new List[n];
        for (int i = 0; i < n; i++) {
            shortest[i] = i;
            fromList[i] = new ArrayList<Integer>();
            fromList[i].add(i - 1);
        }
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int from = queries[i][0], to = queries[i][1];
            fromList[to].add(from);
            for (int j = to; j < n; j++) {
                for (int from_ : fromList[j]) {
                    shortest[j] = Math.min(shortest[j], shortest[from_] + 1);
                }
            }
            ans[i] = shortest[n - 1];
        }
        return ans;
    }
}