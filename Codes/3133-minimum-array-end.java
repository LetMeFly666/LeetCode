/*
 * @Author: LetMeFly
 * @Date: 2024-08-22 23:14:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-22 23:15:21
 */
class Solution {
    public long minEnd(long n, long x) {
        n--;
        for (int in = 0, ix = 0; in < 27; in++, ix++) {
            while (((x >> ix) & 1) != 0) {
                ix++;
            }
            x |= (((n >> in) & 1) << ix);
        }
        return x;
    }
}