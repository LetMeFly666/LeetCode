/*
 * @Author: LetMeFly
 * @Date: 2025-09-05 09:55:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-05 10:42:50
 */
import java.util.Arrays;

class Solution {
    public int numberOfPairs(int[][] points) {
        Arrays.sort(points, (a, b) -> a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]);
        int ans = 0;
        for (int i = 0; i < points.length; i++) {
            int mxY = -1000000001;
            for (int j = i + 1; j < points.length; j++) {
                if (points[j][1] > mxY && points[j][1] <= points[i][1]) {
                    mxY = points[j][1];
                    ans++;
                }
            }
        }
        return ans;
    }
}