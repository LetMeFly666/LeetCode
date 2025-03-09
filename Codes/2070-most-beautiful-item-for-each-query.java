/*
 * @Author: LetMeFly
 * @Date: 2025-03-09 14:08:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-09 14:11:18
 */
import java.util.Arrays;

class Solution {
    private int search(int[][] items, int target) {
        int l = 0, r = items.length - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (items[mid][0] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items,(a, b) -> Integer.compare(a[0], b[0]));
        int cnt = 0;
        for (int[] item : items) {
            cnt = item[1] = Math.max(cnt, item[1]);
        }
        for (int i = 0; i < queries.length; i++) {
            int index = search(items, queries[i]);
            if (index > 0) {
                queries[i] = items[index - 1][1];
            } else {
                queries[i] = 0;
            }
        }
        return queries;
    }
}