/*
 * @Author: LetMeFly
 * @Date: 2025-02-14 10:56:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-14 11:02:35
 */
import java.util.Arrays;


class Solution {
	private int[] v;

	private boolean check(int m, int d) {
        int last = -1000000000;
        for (int t : v) {
            if (t - last >= d) {
                if (--m == 0) {
                    return true;
                }
                last = t;
            }
        }
        return false;
    }

    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        v = position;
        int l = 1, r = v[v.length - 1] - v[0];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(m, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}